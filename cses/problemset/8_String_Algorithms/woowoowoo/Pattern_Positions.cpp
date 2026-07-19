#include <bits/stdc++.h>
using namespace std;

struct Aho {
    struct Node {
        int next[26];
        int fail;
        int dict_idx;
        int min_pos;
        Node() : fail(0), dict_idx(-1), min_pos(1e9) {
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
        trie[v].dict_idx = idx;
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
    vector<int> ans(k, -1);
    int v = 0;
    for (int pos = 0; pos < (int)s.size(); pos++) {
        v = aho.trie[v].next[s[pos] - 'a'];
        int cur = v;
        while (cur != 0) {
            int idx = aho.trie[cur].dict_idx;
            if (idx != -1 && ans[idx] == -1) {
                ans[idx] = pos - len[idx] + 2;
            }
            cur = aho.trie[cur].fail;
        }
    }
    for (int i = 0; i < k; i++) cout << ans[i] << '\n';
    return 0;
}
