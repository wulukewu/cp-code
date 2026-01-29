#!/usr/bin/env node
/**
 * ZeroJudge Problem Crawler
 */

const fs = require('fs');
const path = require('path');
const https = require('https');

function fetchUrl(url) {
    return new Promise((resolve, reject) => {
        const options = {
            headers: {
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36',
            },
        };
        https.get(url, options, (res) => {
            let data = '';
            res.on('data', chunk => data += chunk);
            res.on('end', () => {
                if (res.statusCode >= 400) reject(new Error(`HTTP ${res.statusCode}`));
                else resolve(data);
            });
        }).on('error', reject);
    });
}

async function fetchProblemInfo(problemId) {
    try {
        const url = `https://zerojudge.tw/ShowProblem?problemid=${problemId}`;
        const html = await fetchUrl(url);
        
        // Extract title: <span id="problem_title" class="display-4">A001: 兩數運算</span>
        const titleMatch = html.match(/id="problem_title"[^>]*>([^<]+)<\/span>/);
        let title = titleMatch ? titleMatch[1].trim() : null;
        
        if (title && title.includes(':')) {
            title = title.split(':').slice(1).join(':').trim();
        }

        return { title };
    } catch (e) {
        return { title: null };
    }
}

function scanLocalProblems(baseDir) {
    const problems = [];
    const zjDir = path.join(baseDir, 'zerojudge');
    
    if (!fs.existsSync(zjDir)) return problems;

    const entries = fs.readdirSync(zjDir, { withFileTypes: true });
    for (const entry of entries) {
        if (entry.isFile() && entry.name.endsWith('.cpp')) {
            // Pattern: a001_title.cpp or a001.cpp
            const match = entry.name.match(/^([a-z]\d+)/i);
            if (match) {
                problems.push({
                    file: path.join(zjDir, entry.name),
                    problemId: match[1].toLowerCase(),
                });
            }
        }
    }
    return problems;
}

function generateHeader(info) {
    const lines = [
        '// ' + '='.repeat(50),
        `// Problem   : ZeroJudge ${info.problemId.toUpperCase()} - ${info.title}`,
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
    console.log(`Found ${localProblems.length} local ZeroJudge solutions`);

    const metadata = [];
    for (const p of localProblems) {
        console.log(`Fetching ${p.problemId}...`);
        const info = await fetchProblemInfo(p.problemId);
        
        const data = {
            file: path.relative(baseDir, p.file),
            problemId: p.problemId,
            title: info.title || 'Unknown',
            url: `https://zerojudge.tw/ShowProblem?problemid=${p.problemId}`,
        };
        
        metadata.push(data);
        updateFileHeader(p.file, generateHeader(data));
        await new Promise(r => setTimeout(r, 500)); // Avoid rate limiting
    }

    const outPath = path.join(baseDir, 'zerojudge', 'metadata.json');
    fs.writeFileSync(outPath, JSON.stringify(metadata, null, 2));
    console.log(`Saved metadata to ${outPath}`);
}

main().catch(console.error);
