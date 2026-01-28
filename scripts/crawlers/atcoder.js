#!/usr/bin/env node
/**
 * AtCoder Problem Crawler
 * Scrapes problem titles directly from AtCoder (more reliable than kenkoooo)
 * Also fetches user submissions for runtime info
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

// Scrape problem title from AtCoder contest page
async function fetchProblemTitle(contestId, problemId) {
    try {
        const url = `https://atcoder.jp/contests/${contestId}/tasks/${problemId}`;
        const html = await fetchUrl(url);
        
        // Extract title from <title> tag: "A - Problem Name"
        const titleMatch = html.match(/<title>([A-Z]\d*)\s*-\s*(.+?)<\/title>/);
        if (titleMatch) {
            return titleMatch[2].trim();
        }
        return null;
    } catch (e) {
        return null;
    }
}

// Fetch user submissions from AtCoder directly
async function fetchUserSubmissions(handle, contestId) {
    if (!handle) return [];
    try {
        const url = `https://atcoder.jp/contests/${contestId}/submissions?f.User=${handle}&f.Status=AC`;
        const html = await fetchUrl(url);
        
        // Parse submission table - extract problem and execution time
        const submissions = [];
        const rows = html.match(/<tr[^>]*>[\s\S]*?<\/tr>/g) || [];
        
        for (const row of rows) {
            // Extract problem ID from link
            const problemMatch = row.match(/\/tasks\/([a-z]+\d+_[a-z]\d?)/);
            // Extract execution time
            const timeMatch = row.match(/(\d+)\s*ms/);
            
            if (problemMatch && timeMatch) {
                submissions.push({
                    problem_id: problemMatch[1],
                    execution_time: parseInt(timeMatch[1]),
                });
            }
        }
        return submissions;
    } catch (e) {
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
                // Patterns: "20250201 abc061c.cpp", "abc061c.cpp"
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
    console.log(`Spanning ${contests.length} contests`);
    
    // Fetch missing titles and submissions
    let fetched = 0;
    for (const contestId of contests) {
        const problems = byContest[contestId];
        
        // Fetch submissions for this contest
        if (handle && !cache.submissions[contestId]) {
            console.log(`  Fetching submissions for ${contestId}...`);
            const subs = await fetchUserSubmissions(handle, contestId);
            if (subs.length > 0) {
                cache.submissions[contestId] = subs;
                fetched++;
            }
            // Rate limiting
            await new Promise(r => setTimeout(r, 200));
        }
        
        // Fetch missing problem titles
        for (const p of problems) {
            if (!cache.problems[p.problemId]) {
                console.log(`  Fetching title for ${p.problemId}...`);
                const title = await fetchProblemTitle(p.contestId, p.problemId);
                if (title) {
                    cache.problems[p.problemId] = { title };
                    fetched++;
                }
                // Rate limiting
                await new Promise(r => setTimeout(r, 200));
            }
        }
    }
    
    if (fetched > 0) {
        console.log(`Fetched ${fetched} new items, saving cache...`);
        saveCache(baseDir, cache);
    }
    
    // Build submission map (best time per problem)
    const submissionMap = {};
    for (const contestId in cache.submissions) {
        for (const s of cache.submissions[contestId]) {
            if (!submissionMap[s.problem_id] || s.execution_time < submissionMap[s.problem_id]) {
                submissionMap[s.problem_id] = s.execution_time;
            }
        }
    }
    
    // Update files
    let updated = 0;
    const metadata = [];

    for (const local of localProblems) {
        const cached = cache.problems[local.problemId];
        const runtime = submissionMap[local.problemId];
        
        const info = {
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            title: cached?.title || 'Unknown',
            difficulty: null, // Would need kenkoooo for this
            runtime: runtime,
            url: `https://atcoder.jp/contests/${local.contestId}/tasks/${local.problemId}`,
        };
        
        metadata.push(info);
        
        // Update file with header if we have a title
        if (config.updateExisting !== false && info.title !== 'Unknown') {
            const header = generateHeader(info);
            updateFileHeader(local.file, header);
            updated++;
        }
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
