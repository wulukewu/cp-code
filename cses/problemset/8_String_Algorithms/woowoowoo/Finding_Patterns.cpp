#include <bits/stdc++.h>
using namespace std;

struct Aho {
    struct Node {
        int next[26];
        int fail;
        int out;
        Node() : fail(0), out(-1) {
            fill(next, next + 26, 0);
        }
    };
    vector<Node> trie;
    Aho() { trie.emplace_back(); }
    void insert(const string& s, int idx) {
        int v = 0;
        for (char c : s) {
            int i = c - 'a';
            if (!trie[v].next[i]) {
                trie[v].next[i] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[i];
        }
        trie[v].out = idx;
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (trie[0].next[i]) q.push(trie[0].next[i]);
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                int& to = trie[v].next[i];
                if (to) {
                    trie[to].fail = trie[trie[v].fail].next[i];
                    if (trie[to].out == -1) trie[to].out = trie[trie[to].fail].out;
                    q.push(to);
                } else {
                    to = trie[trie[v].fail].next[i];
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    Aho aho;
    vector<int> len(k);
    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;
        len[i] = p.size();
        aho.insert(p, i);
    }
    aho.build();
    vector<bool> found(k, false);
    int v = 0;
    for (char c : s) {
        v = aho.trie[v].next[c - 'a'];
        int out = aho.trie[v].out;
        while (out != -1) {
            found[out] = true;
            out = aho.trie[aho.trie[v].fail].out;
        }
    }
    for (int i = 0; i < k; i++) cout << (found[i] ? "YES\n" : "NO\n");
    return 0;
}
