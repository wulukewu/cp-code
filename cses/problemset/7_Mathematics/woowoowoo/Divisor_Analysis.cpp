#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MOD2 = 2 * (MOD - 1);

ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pair<ll,ll>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    ll div_cnt = 1, div_sum = 1, n_val = 1, sqrt_n = 1, tau_mod2 = 1;
    for (auto &[p, k] : v) {
        div_cnt = div_cnt * ((k + 1) % MOD) % MOD;
        ll num = (mod_pow(p, k + 1, MOD) - 1 + MOD) % MOD;
        ll den = mod_pow(p - 1, MOD - 2, MOD);
        div_sum = div_sum * num % MOD * den % MOD;
        n_val = n_val * mod_pow(p, k, MOD) % MOD;
        sqrt_n = sqrt_n * mod_pow(p, k / 2, MOD) % MOD;
        tau_mod2 = tau_mod2 * ((k + 1) % MOD2) % MOD2;
    }
    ll div_prod;
    if (tau_mod2 % 2 == 0) {
        ll exp = (tau_mod2 / 2) % (MOD - 1);
        div_prod = mod_pow(n_val, exp, MOD);
    } else {
        ll exp = tau_mod2 % (MOD - 1);
        div_prod = mod_pow(sqrt_n, exp, MOD);
    }
    cout << div_cnt << " " << div_sum << " " << div_prod << "\n";
    return 0;
}
