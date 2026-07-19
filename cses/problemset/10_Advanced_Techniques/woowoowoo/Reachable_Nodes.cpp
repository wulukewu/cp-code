#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
    }
    vector<bitset<50000>> reach(n);
    vector<int> order;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : g[u]) if (!vis[v]) dfs(v);
        order.push_back(u);
    };
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
    for (int u : order) {
        reach[u].set(u);
        for (int v : g[u]) reach[u] |= reach[v];
    }
    for (int i = 0; i < n; i++) cout << reach[i].count() << " \n"[i + 1 == n];
    return 0;
}
