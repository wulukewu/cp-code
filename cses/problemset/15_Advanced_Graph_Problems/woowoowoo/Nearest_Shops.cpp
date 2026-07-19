#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n + 1);
    vector<pair<int,int>> dist[2];
    dist[0].resize(n + 1, {INT_MAX, INT_MAX});
    dist[1].resize(n + 1, {INT_MAX, INT_MAX});
    queue<int> q;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dist[0][x] = {0, x};
        q.push(x);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[0][v].first > dist[0][u].first + 1) {
                dist[1][v] = dist[0][v];
                dist[0][v] = {dist[0][u].first + 1, dist[0][u].second};
                q.push(v);
            } else if (dist[1][v].first > dist[0][u].first + 1 && dist[0][v].second != dist[0][u].second) {
                dist[1][v] = {dist[0][u].first + 1, dist[0][u].second};
            }
        }
    }
    vector<int> ans(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        if (dist[0][i].first != 0) {
            ans[i] = dist[0][i].first;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[1][i].first == INT_MAX) continue;
        int u = dist[0][i].second;
        int v = dist[1][i].second;
        int d = dist[0][i].first + dist[1][i].first;
        if (d < ans[u]) ans[u] = d;
        if (d < ans[v]) ans[v] = d;
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == INT_MAX) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
