#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> vis;
vector<int> order, comp;
int comp_id;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
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
    cout << comp_id << "\n";
    for (int i = 1; i <= n; i++) cout << comp[i] << " \n"[i == n];
    return 0;
}
