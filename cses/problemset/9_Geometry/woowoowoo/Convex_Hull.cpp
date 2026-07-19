#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
    bool operator<(const Point& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
    Point operator-(const Point& o) const {
        return {x - o.x, y - o.y};
    }
};

ll cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

ll cross(const Point& a, const Point& b, const Point& c) {
    return cross(b - a, c - a);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    sort(pts.begin(), pts.end());
    vector<Point> hull;
    int lower = 0;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            while ((int)hull.size() - lower >= 2) {
                Point a = hull[hull.size() - 2];
                Point b = hull[hull.size() - 1];
                if (cross(a, b, pts[i]) <= 0) break;
                hull.pop_back();
            }
            hull.push_back(pts[i]);
        }
        hull.pop_back();
        lower = hull.size();
        reverse(pts.begin(), pts.end());
    }
    cout << hull.size() << "\n";
    for (auto& p : hull) cout << p.x << " " << p.y << "\n";
    return 0;
}
