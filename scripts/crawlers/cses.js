#!/usr/bin/env node
/**
 * CSES Problem Crawler
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

function fetchUrl(url) {
    return new Promise((resolve, reject) => {
        https.get(url, { headers: { 'User-Agent': 'Mozilla/5.0' } }, (res) => {
            let data = '';
            res.on('data', chunk => data += chunk);
            res.on('end', () => {
                if (res.statusCode >= 400) reject(new Error(`HTTP ${res.statusCode}`));
                else resolve(data);
            });
        }).on('error', reject);
    });
}

async function fetchCSESProblemList() {
    console.log('Fetching CSES problem list...');
    const html = await fetchUrl('https://cses.fi/problemset/');
    const problems = {};
    
    // <a href="/problemset/task/1068">Weird Algorithm</a>
    const regex = /<a href="\/problemset\/task\/(\d+)">([^<]+)<\/a>/g;
    let match;
    while ((match = regex.exec(html)) !== null) {
        const id = match[1];
        const title = match[2].trim();
        problems[title.toLowerCase()] = { id, title };
        // Also handle titles without spaces (for filenames)
        problems[title.replace(/\s+/g, '').toLowerCase()] = { id, title };
        problems[title.replace(/\s+/g, '_').toLowerCase()] = { id, title };
    }
    return problems;
}

function scanLocalProblems(baseDir) {
    const problems = [];
    const csesDir = path.join(baseDir, 'cses', 'problemset');
    
    if (!fs.existsSync(csesDir)) return problems;

    function walk(dir) {
        const entries = fs.readdirSync(dir, { withFileTypes: true });
        for (const entry of entries) {
            const fullPath = path.join(dir, entry.name);
            if (entry.isDirectory()) {
                walk(fullPath);
            } else if (entry.name.endsWith('.cpp')) {
                const title = entry.name.replace('.cpp', '').replace(/_/g, ' ');
                problems.push({
                    file: fullPath,
                    filenameTitle: entry.name.replace('.cpp', ''),
                });
            }
        }
    }
    walk(csesDir);
    return problems;
}

function generateHeader(info) {
    const lines = [
        '// ' + '='.repeat(50),
        `// Problem   : CSES - ${info.title}`,
        `// URL       : ${info.url}`,
        '// ' + '='.repeat(50),
    ];
    return lines.join('\n');
}

function updateFileHeader(filePath, header) {
    let content = fs.readFileSync(filePath, 'utf-8');
    const headerPattern = /^\/\/ =+\n(\/\/ .+\n)+\/\/ =+\n*/;
    content = content.replace(headerPattern, '');
    const newContent = header + '\n\n' + content.trimStart();
    fs.writeFileSync(filePath, newContent);
}

async function main() {
    const baseDir = process.argv[2] || '.';
    const [csesMap, localProblems] = await Promise.all([
        fetchCSESProblemList(),
        scanLocalProblems(baseDir)
    ]);
    
    console.log(`Found ${localProblems.length} local CSES solutions`);

    const metadata = [];
    for (const p of localProblems) {
        const match = csesMap[p.filenameTitle.toLowerCase()] || csesMap[p.filenameTitle.replace(/_/g, '').toLowerCase()];
        
        const data = {
            file: path.relative(baseDir, p.file),
            title: match ? match.title : p.filenameTitle.replace(/_/g, ' '),
            url: match ? `https://cses.fi/problemset/task/${match.id}` : 'https://cses.fi/problemset/',
        };
        
        metadata.push(data);
        updateFileHeader(p.file, generateHeader(data));
    }

    const outPath = path.join(baseDir, 'cses', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    console.log(`Saved metadata to ${outPath}`);
}

main().catch(console.error);
