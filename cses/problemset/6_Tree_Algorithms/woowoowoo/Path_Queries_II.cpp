#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegTree {
    int n;
    vector<int> seg;
    SegTree(int sz) {
        n = 1;
        while (n < sz) n <<= 1;
        seg.assign(2 * n, 0);
    }
    void upd(int p, int x) {
        p += n;
        seg[p] = x;
        p >>= 1;
        while (p) {
            seg[p] = max(seg[2 * p], seg[2 * p + 1]);
            p >>= 1;
        }
    }
    int query(int l, int r) {
        l += n; r += n;
        int res = 0;
        while (l <= r) {
            if (l & 1) res = max(res, seg[l++]);
            if (!(r & 1)) res = max(res, seg[r--]);
            l >>= 1; r >>= 1;
        }
        return res;
    }
};

vector<vector<int>> adj;
vector<int> val, parent, depth, heavy, head, pos;
SegTree *st;
int cur_pos;

int dfs(int u) {
    int sz = 1, max_sz = 0;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int csz = dfs(v);
        if (csz > max_sz) max_sz = csz, heavy[u] = v;
        sz += csz;
    }
    return sz;
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = cur_pos++;
    st->upd(pos[u], val[u]);
    if (heavy[u] != -1) decompose(heavy[u], h);
    for (int v : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

int path_max(int u, int v) {
    int res = 0;
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        res = max(res, st->query(pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    res = max(res, st->query(pos[u], pos[v]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, q; cin >> n >> q;
    adj.assign(n + 1, {});
    val.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    heavy.assign(n + 1, -1);
    head.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    cur_pos = 0;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    SegTree seg(n + 1);
    st = &seg;
    dfs(1);
    decompose(1, 1);
    vector<int> ans;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            seg.upd(pos[s], x);
        } else {
            int a, b; cin >> a >> b;
            ans.push_back(path_max(a, b));
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}
