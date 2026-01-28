#!/usr/bin/env node
/**
 * Codeforces Problem Crawler
 * Fetches problem info from Codeforces API
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

function fetch(url) {
    return new Promise((resolve, reject) => {
        https.get(url, { headers: { 'User-Agent': 'cp-code-crawler' } }, (res) => {
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
                // Extract from path like "contest/2178/A_Yes_or_Yes.cpp"
                const relPath = path.relative(cfDir, fullPath);
                const parts = relPath.split(path.sep);
                
                if (parts.length >= 3) {
                    const contestId = parts[1];
                    const problemIndex = entry.name.split('_')[0]; // "A" from "A_Yes_or_Yes.cpp"
                    
                    problems.push({
                        file: fullPath,
                        contestId: parseInt(contestId) || contestId,
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

async function main() {
    const baseDir = process.argv[2] || '.';
    
    // Fetch remote data
    const problems = await fetchProblems();

    // Create lookup map
    const problemMap = {};
    for (const p of problems) {
        const key = `${p.contestId}${p.index}`;
        problemMap[key] = p;
    }

    // Scan local problems
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local Codeforces solutions`);

    // Generate metadata
    const metadata = [];
    for (const local of localProblems) {
        const remote = problemMap[local.problemId];
        
        metadata.push({
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            index: local.problemIndex,
            title: remote?.name || 'Unknown',
            rating: remote?.rating || null,
            tags: remote?.tags || [],
            url: `https://codeforces.com/contest/${local.contestId}/problem/${local.problemIndex}`,
        });
    }

    // Sort by rating
    metadata.sort((a, b) => (a.rating || 0) - (b.rating || 0));

    // Save metadata
    const outPath = path.join(baseDir, 'codeforces', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    console.log(`Saved metadata to ${outPath}`);

    // Print summary
    console.log('\n📊 Codeforces Summary:');
    console.log(`  Total solutions: ${metadata.length}`);
    
    const withRating = metadata.filter(m => m.rating);
    if (withRating.length > 0) {
        const avgRating = withRating.reduce((s, m) => s + m.rating, 0) / withRating.length;
        console.log(`  Avg rating: ${Math.round(avgRating)}`);
        console.log(`  Hardest solved: ${withRating[withRating.length - 1].title} (${withRating[withRating.length - 1].rating})`);
    }

    // Tag distribution
    const tagCounts = {};
    for (const m of metadata) {
        for (const tag of m.tags) {
            tagCounts[tag] = (tagCounts[tag] || 0) + 1;
        }
    }
    const topTags = Object.entries(tagCounts).sort((a, b) => b[1] - a[1]).slice(0, 5);
    if (topTags.length > 0) {
        console.log(`  Top tags: ${topTags.map(([t, c]) => `${t}(${c})`).join(', ')}`);
    }
}

main().catch(console.error);
