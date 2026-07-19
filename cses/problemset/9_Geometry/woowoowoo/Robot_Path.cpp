#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

typedef long long ll;

int n;
vector<pair<int, int>> cmd;

bool ok(ll tot) {
    tot--;
    vector<tuple<ll, ll, ll>> h_seg, v_seg;
    ll x = 0, y = 0;
    ll rem = tot;
    for (int i = 0; i < n && rem > 0; i++) {
        int d = cmd[i].first;
        ll len = min((ll)cmd[i].second, rem);
        if (d == 0) {
            v_seg.push_back({x, y + 1, y + len});
            y += len;
        } else if (d == 1) {
            h_seg.push_back({y, x - len, x - 1});
            x -= len;
        } else if (d == 2) {
            h_seg.push_back({y, x + 1, x + len});
            x += len;
        } else {
            v_seg.push_back({x, y - len, y - 1});
            y -= len;
        }
        rem -= len;
    }
    sort(h_seg.begin(), h_seg.end());
    sort(v_seg.begin(), v_seg.end());
    for (int i = 1; i < (int)h_seg.size(); i++) {
        if (get<0>(h_seg[i]) == get<0>(h_seg[i - 1]) && get<1>(h_seg[i]) <= get<2>(h_seg[i - 1])) return false;
    }
    for (int i = 1; i < (int)v_seg.size(); i++) {
        if (get<0>(v_seg[i]) == get<0>(v_seg[i - 1]) && get<1>(v_seg[i]) <= get<2>(v_seg[i - 1])) return false;
    }
    vector<tuple<ll, ll, int>> events;
    for (auto &seg : h_seg) {
        ll y = get<0>(seg), l = get<1>(seg), r = get<2>(seg);
        events.push_back({l, y, 1});
        events.push_back({r + 1, y, -1});
    }
    sort(events.begin(), events.end());
    multiset<ll> active;
    int pos = 0;
    for (auto &seg : v_seg) {
        ll xi = get<0>(seg), lo = get<1>(seg), hi = get<2>(seg);
        while (pos < (int)events.size() && xi >= get<0>(events[pos])) {
            auto [_, y, t] = events[pos];
            if (t == 1) active.insert(y);
            else active.erase(active.find(y));
            pos++;
        }
        auto it = active.lower_bound(lo);
        if (it != active.end() && *it <= hi) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    cmd.resize(n);
    ll total = 1;
    for (int i = 0; i < n; i++) {
        char c; int len;
        cin >> c >> len;
        total += len;
        if (c == 'U') cmd[i] = {0, len};
        else if (c == 'L') cmd[i] = {1, len};
        else if (c == 'R') cmd[i] = {2, len};
        else cmd[i] = {3, len};
    }
    if (ok(total)) {
        cout << total - 1 << "\n";
        return 0;
    }
    ll lo = 1, hi = total;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
