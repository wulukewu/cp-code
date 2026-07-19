#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

class DSUWithRollback {
public:
    vector<int> parent, rank;
    int comp;
    struct Change {
        int a, b, p, r;
        Change(int a, int b, int p, int r) : a(a), b(b), p(p), r(r) {}
    };
    stack<Change> s;
    DSUWithRollback(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        comp = n;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        s.push(Change(a, b, parent[b], rank[a]));
        parent[b] = parent[a];
        rank[a] += rank[b];
        comp--;
        return true;
    }
    void rollback() {
        auto c = s.top(); s.pop();
        comp++;
        parent[c.b] = c.p;
        rank[c.a] = c.r;
    }
    int components() { return comp; }
};

struct SegTree {
    int n;
    vector<vector<pair<int,int>>> tree;
    DSUWithRollback dsu;
    vector<int> ans;
    SegTree(int sz, int N) : n(sz), tree(4 * sz + 9), dsu(N), ans(sz + 2) {}
    void add(int l, int r, pair<int,int> edge, int node, int nl, int nr) {
        if (l > nr || r < nl) return;
        if (l <= nl && nr <= r) { tree[node].push_back(edge); return; }
        int mid = (nl + nr) / 2;
        add(l, r, edge, node * 2, nl, mid);
        add(l, r, edge, node * 2 + 1, mid + 1, nr);
    }
    void add(int l, int r, pair<int,int> edge) { add(l, r, edge, 1, 0, n); }
    void solve(int b, int e, int node) {
        int cnt = 0;
        for (auto &q : tree[node])
            if (dsu.unite(q.first, q.second)) cnt++;
        if (b == e) { ans[b] = dsu.components(); }
        else {
            int mid = (b + e) / 2;
            solve(b, mid, node * 2);
            solve(mid + 1, e, node * 2 + 1);
        }
        while (cnt--) dsu.rollback();
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k; cin >> n >> m >> k;
    map<pair<int,int>, vector<pair<int,int>>> g;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        g[{a, b}].push_back({0, k + 1});
    }
    for (int i = 1; i <= k; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (a > b) swap(a, b);
        if (t == 1) g[{a, b}].push_back({i, k + 1});
        else g[{a, b}].back().second = i;
    }
    SegTree seg(k + 1, n);
    for (auto &v : g)
        for (auto [l, r] : v.second)
            seg.add(l, r - 1, v.first);
    seg.solve(0, k + 1, 1);
    for (int i = 0; i <= k; i++)
        cout << seg.ans[i] << (i == k ? "\n" : " ");
    return 0;
}
