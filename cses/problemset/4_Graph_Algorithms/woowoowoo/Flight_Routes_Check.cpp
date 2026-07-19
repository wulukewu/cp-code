#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj, radj;
vector<bool> vis;
vector<int> order;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
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
    dfs2(order.back());
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << i << " " << order.back() << "\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
