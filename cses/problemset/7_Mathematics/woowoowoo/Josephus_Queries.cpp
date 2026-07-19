#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll josephus(ll n, ll k) {
    if (n == 1) return 1;
    if (k <= n / 2) return 2 * k;
    ll prev = josephus(n - n / 2, k - n / 2);
    if (n % 2 == 0) return 2 * prev - 1;
    return (prev == 1) ? n : 2 * prev - 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        ll n, k; cin >> n >> k;
        cout << josephus(n, k) << "\n";
    }
    return 0;
}
