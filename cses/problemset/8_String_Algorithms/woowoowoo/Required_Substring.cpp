#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string p;
    cin >> n >> p;
    int m = p.size();
    vector<int> pi = prefix_function(p);
    vector<vector<int>> aut(m + 1, vector<int>(26));
    for (int i = 0; i <= m; i++) {
        for (char c = 'A'; c <= 'Z'; c++) {
            if (i < m && p[i] == c) aut[i][c - 'A'] = i + 1;
            else if (i == 0) aut[i][c - 'A'] = 0;
            else aut[i][c - 'A'] = aut[pi[i - 1]][c - 'A'];
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < 26; c++) {
                int nj = aut[j][c];
                dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++) ans = (ans + dp[n][j]) % MOD;
    int total = 1;
    for (int i = 0; i < n; i++) total = (long long)total * 26 % MOD;
    ans = (total - ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
