#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj, radj, dag;
vector<bool> vis;
vector<int> order, comp;
vector<long long> comp_sum, dp;
int n, m, comp_id;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp[u] = comp_id;
    for (int v : radj[u]) if (!vis[v]) dfs2(v);
}

long long dfs_dp(int u) {
    if (dp[u] != -1) return dp[u];
    dp[u] = comp_sum[u];
    for (int v : dag[u]) dp[u] = max(dp[u], comp_sum[u] + dfs_dp(v));
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];
    adj.assign(n + 1, {});
    radj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs1(i);
    vis.assign(n + 1, false);
    comp.assign(n + 1, 0);
    comp_id = 0;
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (!vis[u]) { comp_id++; dfs2(u); }
    }
    comp_sum.assign(comp_id + 1, 0);
    for (int i = 1; i <= n; i++) comp_sum[comp[i]] += val[i];
    dag.assign(comp_id + 1, {});
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (comp[u] != comp[v]) dag[comp[u]].push_back(comp[v]);
        }
    }
    dp.assign(comp_id + 1, -1);
    long long ans = 0;
    for (int i = 1; i <= comp_id; i++) ans = max(ans, dfs_dp(i));
    cout << ans << "\n";
    return 0;
}
