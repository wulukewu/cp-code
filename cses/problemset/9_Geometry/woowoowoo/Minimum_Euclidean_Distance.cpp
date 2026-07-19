#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll dist2(const Point& a, const Point& b) {
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

ll solve(vector<Point>& pts, int l, int r) {
    if (l >= r) return LLONG_MAX;
    int m = (l + r) / 2;
    ll midx = pts[m].x;
    ll d = min(solve(pts, l, m), solve(pts, m + 1, r));
    inplace_merge(pts.begin() + l, pts.begin() + m + 1, pts.begin() + r + 1,
        [](const Point& a, const Point& b) { return a.y < b.y; });
    vector<Point> strip;
    for (int i = l; i <= r; i++) {
        if ((pts[i].x - midx) * (pts[i].x - midx) < d) strip.push_back(pts[i]);
    }
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist2(strip[i], strip[j]));
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    cout << solve(pts, 0, n - 1) << '\n';
    return 0;
}
