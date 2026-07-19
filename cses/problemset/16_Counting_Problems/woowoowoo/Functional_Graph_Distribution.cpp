#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 5005;

ll fact[MAXN], inv_fact[MAXN], g[MAXN], Q[MAXN][MAXN];

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
    int n; cin >> n;
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv_fact[i] = modpow(fact[i], MOD - 2);
    }
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll sum = 0, powN = 1;
        for (int j = 0; j <= i - 1; j++) {
            sum = (sum + powN * inv_fact[j]) % MOD;
            powN = powN * i % MOD;
        }
        g[i] = fact[i-1] * sum % MOD;
    }
    for (int i = 1; i <= n; i++)
        Q[i][1] = g[i] * inv_fact[i] % MOD;
    for (int i = 1; i <= n; i++) {
        ll f_i = g[i] * inv_fact[i] % MOD;
        for (int s = i + 1; s <= n; s++) {
            for (int k = 2; k <= s; k++) {
                Q[s][k] = (Q[s][k] + f_i * Q[s - i][k - 1]) % MOD;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        ll ans = Q[n][k] * fact[n] % MOD * inv_fact[k] % MOD;
        cout << ans << "\n";
    }
    return 0;
}
