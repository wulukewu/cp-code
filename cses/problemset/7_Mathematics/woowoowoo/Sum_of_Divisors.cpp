#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    ll ans = 0;
    for (ll l = 1, r; l <= n; l = r + 1) {
        ll q = n / l;
        r = n / q;
        ll len = (r - l + 1) % MOD;
        ll sum = (l + r) % MOD * len % MOD * ((MOD + 1) / 2) % MOD;
        ans = (ans + q % MOD * sum) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
