#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(n + 2, vector<ll>(3, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int cur = i & 1, prev = (i - 1) & 1;
        for (int j = 1; j <= i; j++) {
            ll v0 = dp[prev][j+1][0] * (j+1) * j;
            ll v1 = dp[prev][j+1][1] * j * j;
            ll v2 = dp[prev][j+1][2] * j * (j-1);
            dp[cur][j][0] = (v0 + v1 + v2) % MOD;
            v0 = dp[prev][j][0] * 2 * j;
            v1 = dp[prev][j][1] * (2 * j - 1);
            v2 = dp[prev][j][2] * 2 * (j - 1);
            dp[cur][j][1] = (v0 + v1 + v2) % MOD;
            v0 = dp[prev][j-1][0];
            v1 = dp[prev][j-1][1];
            v2 = dp[prev][j-1][2];
            dp[cur][j][2] = (v0 + v1 + v2) % MOD;
        }
    }
    ll ans = (dp[n & 1][1][0] + dp[n & 1][1][1] + dp[n & 1][1][2]) % MOD;
    cout << ans << "\n";
    return 0;
}
