#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> sz;
int n, centroid = -1;

void dfs(int u, int p) {
    sz[u] = 1;
    int mx = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) mx = sz[v];
    }
    if (n - sz[u] > mx) mx = n - sz[u];
    if (mx <= n / 2) centroid = u;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    adj.assign(n + 1, {});
    sz.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << centroid << "\n";
    return 0;
}
