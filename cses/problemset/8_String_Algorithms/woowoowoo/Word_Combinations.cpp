#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Trie {
    struct Node {
        Node* next[26];
        bool isEnd;
        Node() : isEnd(false) {
            fill(next, next + 26, nullptr);
        }
    };
    Node* root;
    Trie() { root = new Node(); }
    void insert(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!cur->next[idx]) cur->next[idx] = new Node();
            cur = cur->next[idx];
        }
        cur->isEnd = true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    Trie trie;
    for (int i = 0; i < k; i++) {
        string w;
        cin >> w;
        trie.insert(w);
    }
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        Trie::Node* cur = trie.root;
        for (int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if (!cur->next[idx]) break;
            cur = cur->next[idx];
            if (cur->isEnd) {
                dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
    }
    cout << dp[0] << '\n';
    return 0;
}
