#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int orient(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    while (m--) {
        ll px, py;
        cin >> px >> py;
        bool on = false;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (orient(x[i], y[i], x[j], y[j], px, py) == 0) {
                if (min(x[i], x[j]) <= px && px <= max(x[i], x[j]) &&
                    min(y[i], y[j]) <= py && py <= max(y[i], y[j])) {
                    on = true;
                    break;
                }
            }
            if ((y[i] > py) != (y[j] > py)) {
                ll cross = (x[j] - x[i]) * (py - y[i]) - (y[j] - y[i]) * (px - x[i]);
                if ((y[j] - y[i]) > 0) { if (cross > 0) cnt++; }
                else { if (cross < 0) cnt++; }
            }
        }
        if (on) cout << "BOUNDARY\n";
        else if (cnt % 2) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
    }
    return 0;
}
