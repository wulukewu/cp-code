#!/usr/bin/env node
/**
 * Master crawler script - runs all site-specific crawlers
 */

const { execSync } = require('child_process');
const path = require('path');
const fs = require('fs');

const CRAWLERS = [
    { name: 'AtCoder', script: 'atcoder.js' },
    { name: 'Codeforces', script: 'codeforces.js' },
    // Add more crawlers here as needed:
    // { name: 'CSES', script: 'cses.js' },
    // { name: 'ZeroJudge', script: 'zerojudge.js' },
];

const baseDir = process.argv[2] || path.join(__dirname, '..', '..');
const crawlersDir = __dirname;

console.log('🚀 Running CP Code Crawlers\n');
console.log(`Base directory: ${baseDir}\n`);

const results = [];

for (const crawler of CRAWLERS) {
    const scriptPath = path.join(crawlersDir, crawler.script);
    
    if (!fs.existsSync(scriptPath)) {
        console.log(`⚠️  ${crawler.name}: Script not found, skipping`);
        continue;
    }

    console.log(`\n${'='.repeat(50)}`);
    console.log(`🔍 ${crawler.name}`);
    console.log('='.repeat(50));

    try {
        execSync(`node "${scriptPath}" "${baseDir}"`, { stdio: 'inherit' });
        results.push({ name: crawler.name, status: 'success' });
    } catch (e) {
        console.error(`❌ ${crawler.name} failed:`, e.message);
        results.push({ name: crawler.name, status: 'failed', error: e.message });
    }
}

// Generate combined summary
console.log(`\n${'='.repeat(50)}`);
console.log('📋 Summary');
console.log('='.repeat(50));

for (const r of results) {
    const icon = r.status === 'success' ? '✅' : '❌';
    console.log(`${icon} ${r.name}: ${r.status}`);
}

// Generate combined stats if metadata files exist
const stats = {
    generatedAt: new Date().toISOString(),
    sites: {},
};

const sites = ['atcoder', 'codeforces', 'cses', 'zerojudge', 'luogu'];
for (const site of sites) {
    const metaPath = path.join(baseDir, site, 'metadata.json');
    if (fs.existsSync(metaPath)) {
        const meta = JSON.parse(fs.readFileSync(metaPath, 'utf-8'));
        stats.sites[site] = {
            count: meta.length,
            withRating: meta.filter(m => m.rating).length,
        };
    }
}

const statsPath = path.join(baseDir, 'stats.json');
fs.writeFileSync(statsPath, JSON.stringify(stats, null, 2));
console.log(`\n📊 Combined stats saved to stats.json`);
