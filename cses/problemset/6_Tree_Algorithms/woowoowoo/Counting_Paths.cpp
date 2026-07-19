#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LOG;
vector<vector<int>> adj, up;
vector<int> depth, diff;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int j = 1; j <= LOG; j++)
        up[u][j] = up[up[u][j-1]][j-1];
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int d = depth[u] - depth[v];
    for (int i = LOG; i >= 0; i--)
        if (d & (1 << i)) u = up[u][i];
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void dfs_sum(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_sum(v, u);
        diff[u] += diff[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    LOG = 0;
    while ((1 << LOG) <= n) LOG++;
    adj.assign(n + 1, {});
    up.assign(n + 1, vector<int>(LOG + 1, 0));
    depth.assign(n + 1, 0);
    diff.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        int w = lca(u, v);
        diff[u]++;
        diff[v]++;
        diff[w]--;
        if (up[w][0]) diff[up[w][0]]--;
    }
    dfs_sum(1, 0);
    for (int i = 1; i <= n; i++) cout << diff[i] << " \n"[i == n];
    return 0;
}
