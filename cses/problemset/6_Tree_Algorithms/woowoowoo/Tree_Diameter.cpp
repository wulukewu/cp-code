#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> adj;

pair<int,int> bfs(int s) {
    int n = adj.size() - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    int far = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > dist[far]) far = u;
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {far, dist[far]};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    adj.assign(n + 1, {});
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int a = bfs(1).first;
    cout << bfs(a).second << "\n";
    return 0;
}
