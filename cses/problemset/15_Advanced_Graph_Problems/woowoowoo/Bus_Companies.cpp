#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> cost(m+1);
    for (int i = 1; i <= m; i++) cin >> cost[i];
    int N = n + m + 1;
    vector<vector<pair<int,ll>>> adj(N);
    for (int i = 1; i <= m; i++) {
        int k; cin >> k;
        int virt = n + i;
        for (int j = 0; j < k; j++) {
            int city; cin >> city;
            adj[city].push_back({virt, cost[i]});
            adj[virt].push_back({city, 0});
        }
    }
    vector<ll> dist(N, 1e18);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " \n"[i==n];
    return 0;
}
