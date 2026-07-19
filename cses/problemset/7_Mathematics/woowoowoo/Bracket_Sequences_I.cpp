#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1e6;

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    if (n % 2 == 1) { cout << "0\n"; return 0; }
    n /= 2;
    vector<ll> fact(2 * n + 1), inv_fact(2 * n + 1);
    fact[0] = 1;
    for (int i = 1; i <= 2 * n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[2 * n] = mod_pow(fact[2 * n], MOD - 2);
    for (int i = 2 * n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    ll ans = fact[2 * n] * inv_fact[n] % MOD * inv_fact[n] % MOD;
    ans = ans * mod_pow(n + 1, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
