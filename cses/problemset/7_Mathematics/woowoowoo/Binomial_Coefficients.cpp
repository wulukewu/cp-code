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
    vector<ll> fact(MAX + 1), inv_fact(MAX + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[MAX] = mod_pow(fact[MAX], MOD - 2);
    for (int i = MAX; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        ll ans = fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
        cout << ans << "\n";
    }
    return 0;
}
