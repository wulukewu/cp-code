#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

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
    ll n; cin >> n;
    ll id = mod_pow(2, n * n);
    ll rot90, rot180;
    if (n % 2 == 0) {
        rot90 = mod_pow(2, n * n / 4);
        rot180 = mod_pow(2, n * n / 2);
    } else {
        rot90 = mod_pow(2, (n * n + 3) / 4);
        rot180 = mod_pow(2, (n * n + 1) / 2);
    }
    ll ans = (id + 2 * rot90 + rot180) % MOD;
    ans = ans * mod_pow(4, MOD - 2) % MOD;
    cout << ans << "\n";
    return 0;
}
