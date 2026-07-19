#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<vector<ll>> dp(2, vector<ll>(k + 1, 0));
    dp[1 & 1][0] = 1;
    for (int i = 2; i <= n; i++) {
        ll sum = 0;
        int cur = i & 1, prev = (i - 1) & 1;
        fill(dp[cur].begin(), dp[cur].end(), 0);
        int p = 0;
        for (int j = 0; j <= k; j++) {
            if (j - p >= i) {
                sum = (sum - dp[prev][p] + MOD) % MOD;
                p++;
            }
            sum = (sum + dp[prev][j]) % MOD;
            dp[cur][j] = sum;
        }
    }
    cout << dp[n & 1][k] << "\n";
    return 0;
}
