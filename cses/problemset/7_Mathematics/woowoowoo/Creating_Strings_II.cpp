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
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    vector<ll> fact(n + 1), inv_fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = mod_pow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
    ll ans = fact[n];
    for (int c : cnt) ans = ans * inv_fact[c] % MOD;
    cout << ans << "\n";
    return 0;
}
