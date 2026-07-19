#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> vis, outdeg;
vector<pair<int,int>> ans;

void dfs(int u) {
    vis[u] = 1;
    for (auto &[v, id] : adj[u]) {
        if (vis[v] != 1) {
            if (!vis[v]) dfs(v);
            if (outdeg[v] & 1) {
                outdeg[v]++;
                ans[id] = {v, u};
            } else {
                outdeg[u]++;
                ans[id] = {u, v};
            }
        }
    }
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, 0);
    outdeg.resize(n + 1, 0);
    ans.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
        if (outdeg[i] & 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (auto &[u, v] : ans) {
        cout << u << " " << v << "\n";
    }
    return 0;
}
