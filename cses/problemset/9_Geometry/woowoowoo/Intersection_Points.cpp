#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 2) {}
    void add(int i, int v) {
        for (i++; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    struct Event {
        int x, y1, y2, type;
        bool operator<(const Event& o) const {
            if (x != o.x) return x < o.x;
            return type < o.type;
        }
    };
    vector<Event> events;
    vector<int> ys;
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            events.push_back({(int)x1, (int)y1, (int)y2, 1});
            ys.push_back(y1);
            ys.push_back(y2);
        } else {
            if (x1 > x2) swap(x1, x2);
            events.push_back({(int)x1, (int)y1, (int)y2, 0});
            events.push_back({(int)x2, (int)y1, (int)y2, 2});
            ys.push_back(y1);
        }
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto comp = [&](int v) { return lower_bound(ys.begin(), ys.end(), v) - ys.begin(); };
    sort(events.begin(), events.end());
    BIT bit(ys.size());
    ll ans = 0;
    for (auto& e : events) {
        if (e.type == 0) {
            bit.add(comp(e.y1), 1);
        } else if (e.type == 2) {
            bit.add(comp(e.y1), -1);
        } else {
            int l = comp(e.y1), r = comp(e.y2);
            ans += bit.sum(r) - (l > 0 ? bit.sum(l - 1) : 0);
        }
    }
    cout << ans << '\n';
    return 0;
}
