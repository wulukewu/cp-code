#!/usr/bin/env node
/**
 * Codeforces Problem Crawler
 * Fetches problem info AND user submissions to inject headers into files
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

const CONFIG_PATH = path.join(__dirname, 'config.json');

function loadConfig() {
    if (fs.existsSync(CONFIG_PATH)) {
        return JSON.parse(fs.readFileSync(CONFIG_PATH, 'utf-8'));
    }
    return { handles: {} };
}

function fetch(url) {
    return new Promise((resolve, reject) => {
        https.get(url, { headers: { 'User-Agent': 'Mozilla/5.0 (compatible; cp-code-crawler/1.0)' } }, (res) => {
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
    console.log('Fetching Codeforces problems...');
    const resp = await fetch('https://codeforces.com/api/problemset.problems');
    if (resp.status !== 'OK') throw new Error('API error');
    return resp.result.problems;
}

async function fetchUserSubmissions(handle) {
    if (!handle) return [];
    console.log(`Fetching submissions for ${handle}...`);
    try {
        const resp = await fetch(`https://codeforces.com/api/user.status?handle=${handle}&from=1&count=10000`);
        if (resp.status !== 'OK') return [];
        // Filter to accepted only
        return resp.result.filter(s => s.verdict === 'OK');
    } catch (e) {
        console.log(`  ⚠️ Could not fetch submissions: ${e.message}`);
        return [];
    }
}

function scanLocalProblems(baseDir) {
    const problems = [];
    const cfDir = path.join(baseDir, 'codeforces');
    
    if (!fs.existsSync(cfDir)) return problems;

    function walk(dir) {
        const entries = fs.readdirSync(dir, { withFileTypes: true });
        for (const entry of entries) {
            const fullPath = path.join(dir, entry.name);
            if (entry.isDirectory()) {
                walk(fullPath);
            } else if (entry.name.endsWith('.cpp')) {
                const relPath = path.relative(cfDir, fullPath);
                const parts = relPath.split(path.sep);
                
                if (parts.length >= 2) {
                    const parentDir = parts[parts.length - 2];
                    const contestId = parseInt(parentDir) || parentDir;
                    let problemIndex = entry.name.split('_')[0].split('.')[0].toUpperCase();
                    
                    problems.push({
                        file: fullPath,
                        contestId,
                        problemIndex,
                        problemId: `${contestId}${problemIndex}`,
                    });
                }
            }
        }
    }
    walk(cfDir);
    return problems;
}

function generateHeader(info) {
    const lines = [
        '// ' + '='.repeat(50),
        `// Problem   : ${info.contestId}${info.index} - ${info.title}`,
    ];
    
    if (info.timeLimit || info.memLimit) {
        const limits = [];
        if (info.timeLimit) limits.push(`${info.timeLimit / 1000} sec`);
        if (info.memLimit) limits.push(`${info.memLimit / 1024 / 1024} MB`);
        lines.push(`// Limits    : ${limits.join(' / ')}`);
    }
    
    if (info.rating) {
        lines.push(`// Rating    : ${info.rating}`);
    }
    if (info.tags && info.tags.length > 0) {
        lines.push(`// Tags      : ${info.tags.join(', ')}`);
    }
    if (info.runtime !== undefined) {
        lines.push(`// Runtime   : ${info.runtime} ms`);
    }
    if (info.memory !== undefined) {
        lines.push(`// Memory    : ${Math.round(info.memory / 1024)} KB`);
    }
    
    lines.push(`// URL       : ${info.url}`);
    lines.push('// ' + '='.repeat(50));
    
    return lines.join('\n');
}

function updateFileHeader(filePath, header) {
    let content = fs.readFileSync(filePath, 'utf-8');
    
    // Remove existing header if present (starts with // === and ends with // ===)
    const headerPattern = /^\/\/ =+\n(\/\/ .+\n)+\/\/ =+\n*/;
    content = content.replace(headerPattern, '');
    
    // Add new header
    const newContent = header + '\n\n' + content.trimStart();
    fs.writeFileSync(filePath, newContent);
}

async function main() {
    const baseDir = process.argv[2] || '.';
    const config = loadConfig();
    const handle = config.handles?.codeforces;
    
    // Fetch remote data
    const [problems, submissions] = await Promise.all([
        fetchProblems(),
        fetchUserSubmissions(handle),
    ]);

    // Create lookup maps
    const problemMap = {};
    for (const p of problems) {
        problemMap[`${p.contestId}${p.index}`] = p;
    }
    
    // Submission map: best submission per problem
    const submissionMap = {};
    for (const s of submissions) {
        const key = `${s.problem.contestId}${s.problem.index}`;
        if (!submissionMap[key] || s.timeConsumedMillis < submissionMap[key].timeConsumedMillis) {
            submissionMap[key] = s;
        }
    }
    console.log(`Found ${Object.keys(submissionMap).length} accepted problems from submissions`);

    // Scan local problems
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local Codeforces solutions`);

    // Update files
    let updated = 0;
    const metadata = [];
    
    for (const local of localProblems) {
        const remote = problemMap[local.problemId];
        const submission = submissionMap[local.problemId];
        
        const info = {
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            index: local.problemIndex,
            title: remote?.name || 'Unknown',
            timeLimit: remote?.timeLimit,
            memLimit: remote?.memoryLimit,
            rating: remote?.rating || null,
            tags: remote?.tags || [],
            runtime: submission?.timeConsumedMillis,
            memory: submission?.memoryConsumedBytes,
            url: `https://codeforces.com/contest/${local.contestId}/problem/${local.problemIndex}`,
        };
        
        metadata.push(info);
        
        // Update file with header
        if (config.updateExisting !== false) {
            const header = generateHeader(info);
            updateFileHeader(local.file, header);
            updated++;
        }
    }

    // Sort by rating
    metadata.sort((a, b) => (a.rating || 0) - (b.rating || 0));

    // Save metadata
    const outPath = path.join(baseDir, 'codeforces', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    
    console.log(`\n📊 Codeforces Summary:`);
    console.log(`  Files updated: ${updated}`);
    console.log(`  Total solutions: ${metadata.length}`);
    
    const withRating = metadata.filter(m => m.rating);
    if (withRating.length > 0) {
        const avgRating = withRating.reduce((s, m) => s + m.rating, 0) / withRating.length;
        console.log(`  Avg rating: ${Math.round(avgRating)}`);
        console.log(`  Hardest solved: ${withRating[withRating.length - 1].title} (${withRating[withRating.length - 1].rating})`);
    }
}

main().catch(console.error);
