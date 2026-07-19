#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Seg {
    int l, r, h, val;
    bool operator<(const Seg& o) const {
        return h < o.h;
    }
};

struct Node {
    int cnt;
    ll len;
};

vector<Node> tree;
vector<int> xs;

void build(int idx, int l, int r) {
    tree[idx] = {0, 0};
    if (l == r) return;
    int m = (l + r) / 2;
    build(idx * 2, l, m);
    build(idx * 2 + 1, m + 1, r);
}

void update(int idx, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        tree[idx].cnt += val;
    } else {
        int m = (l + r) / 2;
        if (ql <= m) update(idx * 2, l, m, ql, qr, val);
        if (qr > m) update(idx * 2 + 1, m + 1, r, ql, qr, val);
    }
    if (tree[idx].cnt) {
        tree[idx].len = xs[r + 1] - xs[l];
    } else if (l == r) {
        tree[idx].len = 0;
    } else {
        tree[idx].len = tree[idx * 2].len + tree[idx * 2 + 1].len;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Seg> segs;
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segs.push_back({(int)x1, (int)x2, (int)y1, 1});
        segs.push_back({(int)x1, (int)x2, (int)y2, -1});
        xs.push_back(x1);
        xs.push_back(x2);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(segs.begin(), segs.end());
    int m = xs.size();
    tree.resize(4 * m);
    build(1, 0, m - 2);
    ll ans = 0;
    int prev_h = segs[0].h;
    for (auto& seg : segs) {
        ll width = tree[1].len;
        ans += width * (seg.h - prev_h);
        int l = lower_bound(xs.begin(), xs.end(), seg.l) - xs.begin();
        int r = lower_bound(xs.begin(), xs.end(), seg.r) - xs.begin() - 1;
        if (l <= r) update(1, 0, m - 2, l, r, seg.val);
        prev_h = seg.h;
    }
    cout << ans << '\n';
    return 0;
}
