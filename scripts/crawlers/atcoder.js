#!/usr/bin/env node
/**
 * AtCoder Problem Crawler
 * Fetches problem info (title, difficulty, tags) from AtCoder Problems API
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

const ATCODER_PROBLEMS_API = 'kenkoooo.com';

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
                const match = entry.name.match(/([a-z]+)(\d+)([a-z])\.cpp$/i);
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

async function main() {
    const baseDir = process.argv[2] || '.';
    
    let problems = [];
    let difficulties = {};

    // Try to fetch remote data (may fail in some environments)
    try {
        [problems, difficulties] = await Promise.all([
            fetchProblems(),
            fetchDifficulties(),
        ]);
    } catch (e) {
        console.log(`⚠️  Could not fetch from AtCoder Problems API: ${e.message}`);
        console.log('   (This usually works on GitHub Actions, may fail locally due to Cloudflare)');
        console.log('   Continuing with local scan only...\n');
    }

    // Create lookup maps
    const problemMap = {};
    for (const p of problems) {
        problemMap[p.id] = p;
    }

    // Scan local problems
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local AtCoder solutions`);

    // Generate metadata
    const metadata = [];
    for (const local of localProblems) {
        const remote = problemMap[local.problemId];
        const difficulty = difficulties[local.problemId];
        
        metadata.push({
            file: path.relative(baseDir, local.file),
            problemId: local.problemId,
            contestId: local.contestId,
            title: remote?.title || 'Unknown',
            difficulty: difficulty?.difficulty || null,
            rating: difficulty?.difficulty ? Math.round(difficulty.difficulty) : null,
            url: `https://atcoder.jp/contests/${local.contestId}/tasks/${local.problemId}`,
        });
    }

    // Sort by difficulty
    metadata.sort((a, b) => (a.rating || 0) - (b.rating || 0));

    // Save metadata
    const outPath = path.join(baseDir, 'atcoder', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    console.log(`Saved metadata to ${outPath}`);

    // Print summary
    console.log('\n📊 AtCoder Summary:');
    console.log(`  Total solutions: ${metadata.length}`);
    
    const withRating = metadata.filter(m => m.rating);
    if (withRating.length > 0) {
        const avgRating = withRating.reduce((s, m) => s + m.rating, 0) / withRating.length;
        console.log(`  Avg difficulty: ${Math.round(avgRating)}`);
        console.log(`  Hardest solved: ${withRating[withRating.length - 1].title} (${withRating[withRating.length - 1].rating})`);
    }
}

main().catch(console.error);
