#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = n + 1;
    for (int s = 1; s <= n; s++) {
        vector<int> dist(n+1, -1);
        vector<int> parent(n+1, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (2 * dist[u] + 1 >= ans) break;
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    if (ans > n) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}
