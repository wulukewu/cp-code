#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<ll> fact(n+1, 1), invfact(n+1, 1);
    auto modpow = [&](ll a, ll b) {
        ll r = 1;
        while (b) { if (b & 1) r = r * a % MOD; a = a * a % MOD; b >>= 1; }
        return r;
    };
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[n] = modpow(fact[n], MOD-2);
    for (int i = n-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;
    auto C = [&](int a, int b) {
        if (b < 0 || b > a) return 0LL;
        return fact[a] * invfact[b] % MOD * invfact[a-b] % MOD;
    };
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int i = 0; i+1 < n; i++) dp[i][i+1] = (s[i] == s[i+1] ? 1 : 0);
    for (int len = 4; len <= n; len += 2) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            for (int k = l+1; k <= r; k += 2) {
                if (s[l] == s[k]) {
                    ll left = (k == l+1) ? 1 : dp[l+1][k-1];
                    ll right = (k == r) ? 1 : dp[k+1][r];
                    if (left && right) {
                        dp[l][r] = (dp[l][r] + left * right % MOD * C((r-l+1)/2, (k-l+1)/2)) % MOD;
                    }
                }
            }
        }
    }
    if (n % 2) cout << "0\n";
    else cout << dp[0][n-1] << "\n";
    return 0;
}
