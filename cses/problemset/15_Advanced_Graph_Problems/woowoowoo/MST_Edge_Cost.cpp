#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int up[200005][18];
int mx[200005][18];
int dep[200005];
vector<pair<int,int>> adj[200005];

void dfs(int u, int p) {
    up[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int k = 1; k < 18; k++) {
        up[u][k] = up[up[u][k - 1]][k - 1];
        mx[u][k] = max(mx[u][k - 1], mx[up[u][k - 1]][k - 1]);
    }
    for (auto &[v, w] : adj[u]) {
        if (v == p) continue;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int query_max(int u, int v) {
    int res = 0;
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int k = 0; k < 18; k++) {
        if (diff >> k & 1) {
            res = max(res, mx[u][k]);
            u = up[u][k];
        }
    }
    if (u == v) return res;
    for (int k = 17; k >= 0; k--) {
        if (up[u][k] != up[v][k]) {
            res = max(res, mx[u][k]);
            res = max(res, mx[v][k]);
            u = up[u][k];
            v = up[v][k];
        }
    }
    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);
    vector<int> in_mst(m, 0);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {w, a, b};
    }
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return get<0>(edges[i]) < get<0>(edges[j]);
    });
    DSU dsu(n);
    ll mst_total = 0;
    for (int idx : order) {
        auto [w, a, b] = edges[idx];
        if (dsu.unite(a, b)) {
            mst_total += w;
            in_mst[idx] = 1;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }
    dfs(1, 0);
    for (int i = 0; i < m; i++) {
        auto [w, a, b] = edges[i];
        if (in_mst[i]) {
            cout << mst_total << "\n";
        } else {
            int max_on_path = query_max(a, b);
            cout << mst_total - max_on_path + w << "\n";
        }
    }
    return 0;
}
