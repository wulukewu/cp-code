#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (!(mask & 1)) continue;
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || !dp[mask][u]) continue;
            for (int v : adj[u]) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] + dp[mask][u]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << "\n";
    return 0;
}
