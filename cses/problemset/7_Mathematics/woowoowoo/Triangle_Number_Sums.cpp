#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_tri(ll n) {
    ll d = 1 + 8 * n;
    ll s = sqrt(d);
    return s * s == d && (s - 1) % 2 == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (is_tri(n)) { cout << "1\n"; continue; }
        ll k = sqrt(2 * n);
        bool ok = false;
        for (ll i = 1; i <= k; i++) {
            ll rem = n - i * (i + 1) / 2;
            if (rem > 0 && is_tri(rem)) { ok = true; break; }
        }
        if (ok) cout << "2\n";
        else cout << "3\n";
    }
    return 0;
}
