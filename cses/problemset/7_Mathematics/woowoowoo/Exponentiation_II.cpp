#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

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
    while (n--) {
        ll a, b, c; cin >> a >> b >> c;
        ll exp = mod_pow(b, c, MOD - 1);
        cout << mod_pow(a, exp, MOD) << "\n";
    }
    return 0;
}
