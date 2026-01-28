#!/usr/bin/env node
/**
 * AtCoder Problem Crawler
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

function fetchWithRetry(url, retries = 3) {
    return new Promise((resolve, reject) => {
        const urlObj = new URL(url);
        const options = {
            hostname: urlObj.hostname,
            path: urlObj.pathname + urlObj.search,
            headers: {
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
                'Accept': 'application/json, text/plain, */*',
                'Accept-Language': 'en-US,en;q=0.9',
                'Cache-Control': 'no-cache',
            },
        };
        
        const attempt = (n) => {
            https.get(options, (res) => {
                let data = '';
                res.on('data', chunk => data += chunk);
                res.on('end', () => {
                    if (res.statusCode >= 400) {
                        if (n > 1) {
                            console.log(`  Retry ${retries - n + 1}/${retries - 1}...`);
                            setTimeout(() => attempt(n - 1), 1000);
                        } else {
                            reject(new Error(`HTTP ${res.statusCode}`));
                        }
                    } else {
                        resolve(JSON.parse(data));
                    }
                });
            }).on('error', (e) => {
                if (n > 1) {
                    setTimeout(() => attempt(n - 1), 1000);
                } else {
                    reject(e);
                }
            });
        };
        attempt(retries);
    });
}

async function fetchProblems() {
    console.log('Fetching AtCoder problems from kenkoooo...');
    return await fetchWithRetry('https://kenkoooo.com/atcoder/resources/problems.json');
}

async function fetchDifficulties() {
    console.log('Fetching difficulty ratings...');
    return await fetchWithRetry('https://kenkoooo.com/atcoder/resources/problem-models.json');
}

async function fetchUserSubmissions(handle) {
    if (!handle) return [];
    console.log(`Fetching submissions for ${handle}...`);
    try {
        const subs = await fetchWithRetry(`https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user=${handle}&from_second=0`);
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
                // Extract problem ID from filename
                // Patterns: "20250201 abc061c.cpp", "abc061c.cpp", "abc061_c.cpp"
                const match = entry.name.match(/([a-z]+)(\d+)[_]?([a-z])(?:\d)?\.cpp$/i);
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
    let apiSuccess = false;

    // Try to fetch remote data
    try {
        problems = await fetchProblems();
        difficulties = await fetchDifficulties();
        submissions = await fetchUserSubmissions(handle);
        apiSuccess = true;
    } catch (e) {
        console.log(`⚠️  Could not fetch from AtCoder Problems API: ${e.message}`);
        console.log('   Will still update files with available info (URL only)');
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
        
        // Update file with header if we have ANY useful info
        // Always update if API succeeded, or if we have submission data
        if (config.updateExisting !== false && (apiSuccess || submission || info.title !== 'Unknown')) {
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
    console.log(`  API success: ${apiSuccess ? 'Yes' : 'No (will retry on next run)'}`);
    
    const withRating = metadata.filter(m => m.difficulty);
    if (withRating.length > 0) {
        const avgRating = withRating.reduce((s, m) => s + m.difficulty, 0) / withRating.length;
        console.log(`  Avg difficulty: ${Math.round(avgRating)}`);
        console.log(`  Hardest solved: ${withRating[withRating.length - 1].title} (${withRating[withRating.length - 1].difficulty})`);
    }
    
    // Exit with error if API failed so GitHub Actions knows to retry
    if (!apiSuccess && problems.length === 0) {
        process.exit(1);
    }
}

main().catch(e => {
    console.error(e);
    process.exit(1);
});
