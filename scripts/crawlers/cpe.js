#!/usr/bin/env node
/**
 * CPE (UVA) Problem Crawler
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

async function fetchUvaInfo(problemNum) {
    try {
        const data = await fetchUrl(`https://uhunt.onlinejudge.org/api/p/num/${problemNum}`);
        return JSON.parse(data);
    } catch (e) {
        return null;
    }
}

function scanLocalProblems(baseDir) {
    const problems = [];
    const cpeDir = path.join(baseDir, 'cpe');
    
    if (!fs.existsSync(cpeDir)) return problems;

    function walk(dir) {
        const entries = fs.readdirSync(dir, { withFileTypes: true });
        for (const entry of entries) {
            const fullPath = path.join(dir, entry.name);
            if (entry.isDirectory()) {
                walk(fullPath);
            } else if (entry.name.endsWith('.cpp')) {
                // 10008_Whats_Cryptanalysis.cpp
                const match = entry.name.match(/^(\d+)/);
                if (match) {
                    problems.push({
                        file: fullPath,
                        problemNum: match[1],
                    });
                }
            }
        }
    }
    walk(cpeDir);
    return problems;
}

function generateHeader(info) {
    const lines = [
        '// ' + '='.repeat(50),
        `// Problem   : CPE ${info.problemNum} - ${info.title}`,
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
    const localProblems = scanLocalProblems(baseDir);
    console.log(`Found ${localProblems.length} local CPE solutions`);

    const metadata = [];
    for (const p of localProblems) {
        console.log(`Fetching UVA ${p.problemNum}...`);
        const info = await fetchUvaInfo(p.problemNum);
        
        const data = {
            file: path.relative(baseDir, p.file),
            problemNum: p.problemNum,
            title: info ? info.title : p.problemNum,
            url: `https://onlinejudge.org/external/${Math.floor(p.problemNum / 100)}/${p.problemNum}.pdf`,
        };
        
        metadata.push(data);
        updateFileHeader(p.file, generateHeader(data));
        await new Promise(r => setTimeout(r, 200));
    }

    const outPath = path.join(baseDir, 'cpe', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    console.log(`Saved metadata to ${outPath}`);
}

main().catch(console.error);
