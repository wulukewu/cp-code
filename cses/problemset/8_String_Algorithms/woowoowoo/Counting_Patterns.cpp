#include <bits/stdc++.h>
using namespace std;

struct Aho {
    struct Node {
        int next[26];
        int fail;
        int cnt;
        int dict_idx;
        Node() : fail(0), cnt(0), dict_idx(-1) {
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
    vector<string> pat(k);
    for (int i = 0; i < k; i++) {
        cin >> pat[i];
        aho.insert(pat[i], i);
    }
    aho.build();
    int v = 0;
    for (char c : s) {
        v = aho.trie[v].next[c - 'a'];
        aho.trie[v].cnt++;
    }
    vector<int> order(aho.trie.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return aho.trie[a].fail < aho.trie[b].fail;
    });
    vector<int> ans(k, 0);
    for (int i = (int)order.size() - 1; i > 0; i--) {
        int v = order[i];
        int f = aho.trie[v].fail;
        aho.trie[f].cnt += aho.trie[v].cnt;
        if (aho.trie[v].dict_idx != -1) {
            ans[aho.trie[v].dict_idx] = aho.trie[v].cnt;
        }
    }
    if (aho.trie[0].dict_idx != -1) ans[aho.trie[0].dict_idx] = aho.trie[0].cnt;
    for (int i = 0; i < k; i++) cout << ans[i] << '\n';
    return 0;
}
