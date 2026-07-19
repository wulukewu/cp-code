#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 - x2 * y1;
}

int orient(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll c = cross(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    if (c > 0) return 1;
    if (c < 0) return -1;
    return 0;
}

bool on_seg(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return min(x1, x2) <= x3 && x3 <= max(x1, x2) &&
           min(y1, y2) <= y3 && y3 <= max(y1, y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int o1 = orient(x1, y1, x2, y2, x3, y3);
        int o2 = orient(x1, y1, x2, y2, x4, y4);
        int o3 = orient(x3, y3, x4, y4, x1, y1);
        int o4 = orient(x3, y3, x4, y4, x2, y2);
        if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
            if (on_seg(x1, y1, x2, y2, x3, y3) || on_seg(x1, y1, x2, y2, x4, y4) ||
                on_seg(x3, y3, x4, y4, x1, y1) || on_seg(x3, y3, x4, y4, x2, y2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (o1 * o2 <= 0 && o3 * o4 <= 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
