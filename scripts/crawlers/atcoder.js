#!/usr/bin/env node
/**
 * AtCoder Problem Crawler
 * Scrapes problem info directly from AtCoder, including:
 * - Problem title
 * - Time/memory limits
 * - User's best submission runtime
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

function fetchUrl(url) {
    return new Promise((resolve, reject) => {
        const urlObj = new URL(url);
        const options = {
            hostname: urlObj.hostname,
            path: urlObj.pathname + urlObj.search,
            headers: {
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36',
                'Accept': 'text/html,application/json',
                'Accept-Language': 'en-US,en;q=0.9',
            },
        };
        
        https.get(options, (res) => {
            let data = '';
            res.on('data', chunk => data += chunk);
            res.on('end', () => {
                if (res.statusCode >= 400) {
                    reject(new Error(`HTTP ${res.statusCode}`));
                } else {
                    resolve(data);
                }
            });
        }).on('error', reject);
    });
}

// Scrape problem info from AtCoder
async function fetchProblemInfo(contestId, problemId) {
    try {
        const url = `https://atcoder.jp/contests/${contestId}/tasks/${problemId}`;
        const html = await fetchUrl(url);
        
        // Extract title from <title> tag
        const titleMatch = html.match(/<title>([A-Z]\d*)\s*-\s*(.+?)<\/title>/);
        const title = titleMatch ? titleMatch[2].trim() : null;
        
        // Extract time limit: "Time Limit: 2 sec"
        const timeLimitMatch = html.match(/Time Limit:\s*(\d+)\s*sec/i);
        const timeLimit = timeLimitMatch ? parseInt(timeLimitMatch[1]) : null;
        
        // Extract memory limit: "Memory Limit: 1024 MB"
        const memLimitMatch = html.match(/Memory Limit:\s*(\d+)\s*(MB|MiB)/i);
        const memLimit = memLimitMatch ? parseInt(memLimitMatch[1]) : null;
        
        return { title, timeLimit, memLimit };
    } catch (e) {
        return { title: null, timeLimit: null, memLimit: null };
    }
}

// Fetch user's AC submissions for a contest
async function fetchUserSubmissions(handle, contestId) {
    if (!handle) return [];
    try {
        const url = `https://atcoder.jp/contests/${contestId}/submissions?f.User=${handle}&f.Status=AC`;
        const html = await fetchUrl(url);
        
        const submissions = [];
        
        // Find all table rows in submission table
        // Pattern: problem link, result, runtime, memory
        const regex = /href="\/contests\/[^"]+\/tasks\/([a-z]+\d+_[a-z]\d?)"[^>]*>.*?<td[^>]*>AC<\/td>\s*<td[^>]*>(\d+)\s*ms<\/td>\s*<td[^>]*>(\d+)\s*(KB|MB)/gi;
        
        let match;
        while ((match = regex.exec(html)) !== null) {
            submissions.push({
                problem_id: match[1],
                runtime: parseInt(match[2]),
                memory: match[4] === 'MB' ? parseInt(match[3]) * 1024 : parseInt(match[3]),
            });
        }
        
        // If no match with the complex regex, try simpler extraction
        if (submissions.length === 0) {
            // Look for submission rows
            const rows = html.split(/<tr[^>]*>/);
            for (const row of rows) {
                const problemMatch = row.match(/\/tasks\/([a-z]+\d+_[a-z]\d?)/);
                const runtimeMatch = row.match(/>(\d+)\s*ms</);
                const memoryMatch = row.match(/>(\d+)\s*(KB|MB)</);
                const acMatch = row.includes('>AC<');
                
                if (problemMatch && runtimeMatch && acMatch) {
                    const mem = memoryMatch ? (memoryMatch[2] === 'MB' ? parseInt(memoryMatch[1]) * 1024 : parseInt(memoryMatch[1])) : null;
                    submissions.push({
                        problem_id: problemMatch[1],
                        runtime: parseInt(runtimeMatch[1]),
                        memory: mem,
                    });
                }
            }
        }
        
        return submissions;
    } catch (e) {
        console.log(`  ⚠️ Could not fetch submissions for ${contestId}: ${e.message}`);
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
                // Try old convention: 20240706 abc360a.cpp
                const oldMatch = entry.name.match(/([a-z]+)(\d+)[_]?([a-z])(?:\d)?\.cpp$/i);
                if (oldMatch) {
                    const contest = oldMatch[1].toLowerCase() + oldMatch[2];
                    const problem = oldMatch[3].toLowerCase();
                    problems.push({
                        file: fullPath,
                        contestId: contest,
                        problemId: `${contest}_${problem}`,
                    });
                    continue;
                }

                // Try new convention: atcoder/abc/abc397/A_Thermometer.cpp
                const relPath = path.relative(atcoderDir, fullPath);
                const parts = relPath.split(path.sep);
                // parts could be ['abc', 'abc397', 'A_Thermometer.cpp']
                if (parts.length >= 3) {
                    const contest = parts[1].toLowerCase();
                    const problemMatch = entry.name.match(/^([a-z])(?:\d)?_/i);
                    if (problemMatch) {
                        const problem = problemMatch[1].toLowerCase();
                        problems.push({
                            file: fullPath,
                            contestId: contest,
                            problemId: `${contest}_${problem}`,
                        });
                    }
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
    
    if (info.timeLimit || info.memLimit) {
        const limits = [];
        if (info.timeLimit) limits.push(`${info.timeLimit} sec`);
        if (info.memLimit) limits.push(`${info.memLimit} MB`);
        lines.push(`// Limits    : ${limits.join(' / ')}`);
    }
    
    if (info.runtime !== undefined && info.runtime !== null) {
        lines.push(`// Runtime   : ${info.runtime} ms`);
    }
    if (info.memory !== undefined && info.memory !== null) {
        lines.push(`// Memory    : ${info.memory} KB`);
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

// Load cached problem data
function loadCache(baseDir) {
    const cachePath = path.join(baseDir, 'scripts', 'crawlers', 'atcoder_cache.json');
    if (fs.existsSync(cachePath)) {
        return JSON.parse(fs.readFileSync(cachePath, 'utf-8'));
    }
    return { problems: {}, submissions: {} };
}

function saveCache(baseDir, cache) {
    const cachePath = path.join(baseDir, 'scripts', 'crawlers', 'atcoder_cache.json');
    fs.writeFileSync(cachePath, JSON.stringify(cache, null, 2));
}

async function main() {
    const baseDir = process.argv[2] || '.';
    const config = loadConfig();
    const handle = config.handles?.atcoder;
    
    console.log(`AtCoder handle: ${handle || '(not set)'}`);
    
    // Load cache
    const cache = loadCache(baseDir);
    
    // Scan local problems
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local AtCoder solutions`);
    
    // Group by contest for efficient fetching
    const byContest = {};
    for (const p of localProblems) {
        if (!byContest[p.contestId]) byContest[p.contestId] = [];
        byContest[p.contestId].push(p);
    }
    
    const contests = Object.keys(byContest);
    console.log(`Spanning ${contests.length} contests\n`);
    
    // Fetch missing data
    let fetched = 0;
    for (const contestId of contests) {
        const problems = byContest[contestId];
        
        // Fetch submissions for this contest (always refresh to get latest)
        if (handle) {
            console.log(`Fetching submissions for ${contestId}...`);
            const subs = await fetchUserSubmissions(handle, contestId);
            if (subs.length > 0) {
                cache.submissions[contestId] = subs;
                console.log(`  Found ${subs.length} AC submissions`);
            }
            await new Promise(r => setTimeout(r, 300));
        }
        
        // Fetch missing problem info
        for (const p of problems) {
            if (!cache.problems[p.problemId] || !cache.problems[p.problemId].title) {
                console.log(`Fetching info for ${p.problemId}...`);
                const info = await fetchProblemInfo(p.contestId, p.problemId);
                if (info.title) {
                    cache.problems[p.problemId] = info;
                    fetched++;
                }
                await new Promise(r => setTimeout(r, 200));
            }
        }
    }
    
    if (fetched > 0) {
        console.log(`\nFetched ${fetched} new items, saving cache...`);
    }
    saveCache(baseDir, cache);
    
    // Build submission map (best time per problem)
    const submissionMap = {};
    for (const contestId in cache.submissions) {
        for (const s of cache.submissions[contestId]) {
            if (!submissionMap[s.problem_id] || s.runtime < submissionMap[s.problem_id].runtime) {
                submissionMap[s.problem_id] = s;
            }
        }
    }
    console.log(`Submission data for ${Object.keys(submissionMap).length} problems`);
    
    // Update ALL files
    let updated = 0;
    const metadata = [];

    for (const local of localProblems) {
        const cached = cache.problems[local.problemId] || {};
        const submission = submissionMap[local.problemId];
        
        const info = {
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            title: cached.title || 'Unknown',
            timeLimit: cached.timeLimit || null,
            memLimit: cached.memLimit || null,
            runtime: submission?.runtime,
            memory: submission?.memory,
            url: `https://atcoder.jp/contests/${local.contestId}/tasks/${local.problemId}`,
        };
        
        metadata.push(info);
        
        // Update file with header (ALWAYS update)
        const header = generateHeader(info);
        updateFileHeader(local.file, header);
        updated++;
    }

    // Save metadata
    const outPath = path.join(baseDir, 'atcoder', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    
    console.log(`\n📊 AtCoder Summary:`);
    console.log(`  Files updated: ${updated}`);
    console.log(`  Total solutions: ${metadata.length}`);
    console.log(`  With titles: ${metadata.filter(m => m.title !== 'Unknown').length}`);
    console.log(`  With runtime: ${metadata.filter(m => m.runtime).length}`);
}

main().catch(e => {
    console.error(e);
    process.exit(1);
});
