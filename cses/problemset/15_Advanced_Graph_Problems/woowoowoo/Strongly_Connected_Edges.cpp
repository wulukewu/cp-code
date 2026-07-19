#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int,int>>> adj;
vector<bool> used;
vector<int> tin, low;
int timer;
bool has_bridge = false;
vector<pair<int,int>> ans;

void dfs(int u) {
    tin[u] = low[u] = ++timer;
    for (auto &[v, id] : adj[u]) {
        if (used[id]) continue;
        used[id] = true;
        ans.push_back({u, v});
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                has_bridge = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    used.resize(m + 1, false);
    tin.resize(n + 1, 0);
    low.resize(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dfs(1);
    if (has_bridge) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (auto &[u, v] : ans) {
        cout << u << " " << v << "\n";
    }
    return 0;
}
