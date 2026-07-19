#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; int k;
    cin >> n >> k;
    vector<ll> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        ll prod = 1;
        int bits = 0;
        bool ok = true;
        for (int i = 0; i < k; i++) {
            if (mask >> i & 1) {
                bits++;
                if (prod > n / p[i]) { ok = false; break; }
                prod *= p[i];
            }
        }
        if (!ok) continue;
        if (bits % 2 == 1) ans += n / prod;
        else ans -= n / prod;
    }
    cout << ans << "\n";
    return 0;
}
