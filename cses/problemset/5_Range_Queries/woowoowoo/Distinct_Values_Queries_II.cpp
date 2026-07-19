#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxN = 200000;
const int SIZE = 800000;

int N, Q, a[maxN + 1];
int lo[SIZE], hi[SIZE], mn[SIZE], mx[SIZE];
unordered_map<int, set<int, greater<int>>> prv;
unordered_map<int, set<int>> nxt;
unordered_map<int, int> seg_idx;

void pull(int i) {
    mn[i] = min(mn[2 * i], mn[2 * i + 1]);
    mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

void init(int i, int l, int r) {
    lo[i] = l; hi[i] = r;
    if (l == r) {
        int v = a[l];
        mn[i] = (nxt[v].upper_bound(l) == nxt[v].end()) ? INF : *nxt[v].upper_bound(l);
        mx[i] = (prv[v].upper_bound(l) == prv[v].end()) ? -INF : *prv[v].upper_bound(l);
        seg_idx[l] = i;
        return;
    }
    int m = l + (r - l) / 2;
    init(2 * i, l, m);
    init(2 * i + 1, m + 1, r);
    pull(i);
}

void assign(int pos, int mnv, int mxv) {
    int i = seg_idx[pos];
    if (mnv != -1) mn[i] = mnv;
    if (mxv != -1) mx[i] = mxv;
    while (i > 1) {
        i >>= 1;
        pull(i);
    }
}

pair<int,int> query(int i, int l, int r) {
    if (l > hi[i] || r < lo[i]) return {INF, -INF};
    if (l <= lo[i] && hi[i] <= r) return {mn[i], mx[i]};
    auto left = query(2 * i, l, r);
    auto right = query(2 * i + 1, l, r);
    return {min(left.first, right.first), max(left.second, right.second)};
}

void update(int pos, int val) {
    int old = a[pos];
    int old_nxt = (nxt[old].upper_bound(pos) == nxt[old].end()) ? INF : *nxt[old].upper_bound(pos);
    int old_prv = (prv[old].upper_bound(pos) == prv[old].end()) ? -INF : *prv[old].upper_bound(pos);
    prv[old].erase(pos);
    nxt[old].erase(pos);
    if (old_nxt != INF) assign(old_nxt, -1, old_prv);
    if (old_prv != -INF) assign(old_prv, old_nxt, -1);
    a[pos] = val;
    int new_nxt = (nxt[val].upper_bound(pos) == nxt[val].end()) ? INF : *nxt[val].upper_bound(pos);
    int new_prv = (prv[val].upper_bound(pos) == prv[val].end()) ? -INF : *prv[val].upper_bound(pos);
    prv[val].insert(pos);
    nxt[val].insert(pos);
    assign(pos, new_nxt, new_prv);
    if (new_nxt != INF) assign(new_nxt, -1, pos);
    if (new_prv != -INF) assign(new_prv, pos, -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    seg_idx.reserve(N);
    prv.reserve(N + Q);
    nxt.reserve(N + Q);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        prv[a[i]].insert(i);
        nxt[a[i]].insert(i);
    }
    init(1, 1, N);
    for (int q = 0, k, x, y; q < Q; q++) {
        cin >> k >> x >> y;
        if (k == 1) update(x, y);
        else {
            auto res = query(1, x, y);
            int mnv = res.first, mxv = res.second;
            cout << (mnv <= y || mxv >= x ? "NO" : "YES") << '\n';
        }
    }
    return 0;
}
