#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> tin;
int timer;

void dfs(int u) {
    tin[u] = timer++;
    for (int v : adj[u]) {
        if (tin[v] == -1) dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    tin.assign(n + 1, -1);
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    timer = 0;
    for (int i = n; i >= 1; i--) {
        if (tin[i] == -1) dfs(i);
    }
    for (auto &[u, v] : edges) {
        if (tin[u] < tin[v]) cout << u << " " << v << "\n";
        else cout << v << " " << u << "\n";
    }
    return 0;
}
