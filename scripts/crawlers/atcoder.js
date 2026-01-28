#!/usr/bin/env node
/**
 * AtCoder Problem Crawler
 * Fetches problem info AND user submissions to inject headers into files
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

const CONFIG_PATH = path.join(__dirname, 'config.json');
const ATCODER_PROBLEMS_API = 'kenkoooo.com';

function loadConfig() {
    if (fs.existsSync(CONFIG_PATH)) {
        return JSON.parse(fs.readFileSync(CONFIG_PATH, 'utf-8'));
    }
    return { handles: {} };
}

function fetch(hostname, urlPath) {
    return new Promise((resolve, reject) => {
        const options = {
            hostname,
            path: urlPath,
            headers: {
                'User-Agent': 'Mozilla/5.0 (compatible; cp-code-crawler/1.0)',
                'Accept': 'application/json',
            },
        };
        https.get(options, (res) => {
            let data = '';
            res.on('data', chunk => data += chunk);
            res.on('end', () => {
                if (res.statusCode >= 400) reject(new Error(`HTTP ${res.statusCode}`));
                else resolve(JSON.parse(data));
            });
        }).on('error', reject);
    });
}

async function fetchProblems() {
    console.log('Fetching AtCoder problems...');
    return await fetch(ATCODER_PROBLEMS_API, '/atcoder/resources/problems.json');
}

async function fetchDifficulties() {
    console.log('Fetching difficulty ratings...');
    return await fetch(ATCODER_PROBLEMS_API, '/atcoder/resources/problem-models.json');
}

async function fetchUserSubmissions(handle) {
    if (!handle) return [];
    console.log(`Fetching submissions for ${handle}...`);
    try {
        // kenkoooo API for user submissions
        const subs = await fetch(ATCODER_PROBLEMS_API, `/atcoder/atcoder-api/v3/user/submissions?user=${handle}&from_second=0`);
        // Filter to accepted
        return subs.filter(s => s.result === 'AC');
    } catch (e) {
        console.log(`  ⚠️ Could not fetch submissions: ${e.message}`);
        return [];
    }
}

function scanLocalProblems(baseDir) {
    const problems = [];
    const atcoderDir = path.join(baseDir, 'atcoder');
    
    if (!fs.existsSync(atcoderDir)) return problems;

    function walk(dir) {
        const entries = fs.readdirSync(dir, { withFileTypes: true });
        for (const entry of entries) {
            const fullPath = path.join(dir, entry.name);
            if (entry.isDirectory()) {
                walk(fullPath);
            } else if (entry.name.endsWith('.cpp')) {
                // Extract problem ID from filename, e.g., "20250201 abc061c.cpp" -> "abc061_c"
                const match = entry.name.match(/([a-z]+)(\d+)([a-z]\d?)\.cpp$/i);
                if (match) {
                    const contest = match[1].toLowerCase() + match[2];
                    const problem = match[3].toLowerCase();
                    problems.push({
                        file: fullPath,
                        contestId: contest,
                        problemId: `${contest}_${problem}`,
                    });
                }
            }
        }
    }
    walk(atcoderDir);
    return problems;
}

function generateHeader(info) {
    const lines = [
        '// ' + '='.repeat(50),
        `// Problem   : ${info.problemId.toUpperCase()} - ${info.title}`,
    ];
    
    if (info.difficulty !== null && info.difficulty !== undefined) {
        lines.push(`// Difficulty: ${info.difficulty}`);
    }
    if (info.runtime !== undefined) {
        lines.push(`// Runtime   : ${info.runtime} ms`);
    }
    if (info.language) {
        lines.push(`// Language  : ${info.language}`);
    }
    
    lines.push(`// URL       : ${info.url}`);
    lines.push('// ' + '='.repeat(50));
    
    return lines.join('\n');
}

function updateFileHeader(filePath, header) {
    let content = fs.readFileSync(filePath, 'utf-8');
    
    // Remove existing header if present
    const headerPattern = /^\/\/ =+\n(\/\/ .+\n)+\/\/ =+\n*/;
    content = content.replace(headerPattern, '');
    
    // Add new header
    const newContent = header + '\n\n' + content.trimStart();
    fs.writeFileSync(filePath, newContent);
}

async function main() {
    const baseDir = process.argv[2] || '.';
    const config = loadConfig();
    const handle = config.handles?.atcoder;
    
    let problems = [];
    let difficulties = {};
    let submissions = [];

    // Try to fetch remote data
    try {
        [problems, difficulties, submissions] = await Promise.all([
            fetchProblems(),
            fetchDifficulties(),
            fetchUserSubmissions(handle),
        ]);
    } catch (e) {
        console.log(`⚠️  Could not fetch from AtCoder Problems API: ${e.message}`);
        console.log('   (This usually works on GitHub Actions, may fail locally due to Cloudflare)');
    }

    // Create lookup maps
    const problemMap = {};
    for (const p of problems) {
        problemMap[p.id] = p;
    }
    
    // Submission map: best submission per problem
    const submissionMap = {};
    for (const s of submissions) {
        const key = s.problem_id;
        if (!submissionMap[key] || s.execution_time < submissionMap[key].execution_time) {
            submissionMap[key] = s;
        }
    }
    if (submissions.length > 0) {
        console.log(`Found ${Object.keys(submissionMap).length} accepted problems from submissions`);
    }

    // Scan local problems
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local AtCoder solutions`);

    // Update files
    let updated = 0;
    const metadata = [];

    for (const local of localProblems) {
        const remote = problemMap[local.problemId];
        const difficulty = difficulties[local.problemId];
        const submission = submissionMap[local.problemId];
        
        const info = {
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            title: remote?.title || 'Unknown',
            difficulty: difficulty?.difficulty ? Math.round(difficulty.difficulty) : null,
            runtime: submission?.execution_time,
            language: submission?.language,
            url: `https://atcoder.jp/contests/${local.contestId}/tasks/${local.problemId}`,
        };
        
        metadata.push(info);
        
        // Update file with header
        if (config.updateExisting !== false && (info.title !== 'Unknown' || submission)) {
            const header = generateHeader(info);
            updateFileHeader(local.file, header);
            updated++;
        }
    }

    // Sort by difficulty
    metadata.sort((a, b) => (a.difficulty || 0) - (b.difficulty || 0));

    // Save metadata
    const outPath = path.join(baseDir, 'atcoder', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    
    console.log(`\n📊 AtCoder Summary:`);
    console.log(`  Files updated: ${updated}`);
    console.log(`  Total solutions: ${metadata.length}`);
    
    const withRating = metadata.filter(m => m.difficulty);
    if (withRating.length > 0) {
        const avgRating = withRating.reduce((s, m) => s + m.difficulty, 0) / withRating.length;
        console.log(`  Avg difficulty: ${Math.round(avgRating)}`);
        console.log(`  Hardest solved: ${withRating[withRating.length - 1].title} (${withRating[withRating.length - 1].difficulty})`);
    }
}

main().catch(console.error);
