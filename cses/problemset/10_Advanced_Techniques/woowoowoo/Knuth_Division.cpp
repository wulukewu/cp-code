#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<long long> a(n), p(n + 1);
    for (int i = 0; i < n; i++) { cin >> a[i]; p[i + 1] = p[i] + a[i]; }
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n; i++) opt[i][i] = i;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = 1e18;
            for (int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++) {
                long long cur = dp[i][k] + dp[k + 1][j] + p[j + 1] - p[i];
                if (cur < dp[i][j]) { dp[i][j] = cur; opt[i][j] = k; }
            }
        }
    }
    cout << dp[0][n - 1] << "\n";
    return 0;
}
