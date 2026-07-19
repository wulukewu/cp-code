#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 5005;

ll fact[MAXN], inv_fact[MAXN];

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv_fact[i] = modpow(fact[i], MOD - 2);
    }
    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;
    ll H = 1;
    for (int c = 0; c < 26; c++) H = H * inv_fact[cnt[c]] % MOD;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int c = 0; c < 26; c++) {
        int a = cnt[c];
        if (a == 0) continue;
        vector<ll> ndp(n + 1, 0);
        for (int t = 0; t <= n; t++) {
            if (dp[t] == 0) continue;
            ndp[t] = (ndp[t] + dp[t]) % MOD;
            if (t + a <= n)
                ndp[t + a] = (ndp[t + a] - dp[t] * fact[a] % MOD + MOD) % MOD;
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int t = 0; t <= n; t++) {
        ans = (ans + dp[t] * fact[n - t]) % MOD;
    }
    ans = ans * H % MOD;
    cout << ans << "\n";
    return 0;
}
