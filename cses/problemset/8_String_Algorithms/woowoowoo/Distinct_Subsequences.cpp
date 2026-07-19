#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    vector<int> last(26, -1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2) % MOD;
        int idx = s[i - 1] - 'a';
        if (last[idx] != -1) {
            dp[i] = (dp[i] - dp[last[idx] - 1] + MOD) % MOD;
        }
        last[idx] = i;
    }
    cout << (dp[n] - 1 + MOD) % MOD << '\n';
    return 0;
}
