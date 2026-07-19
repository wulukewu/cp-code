#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e17; // 確保大於 2 * 10^5 * 10^9
const int MOD = 1e9 + 7;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 鄰接串列：pair<目標節點, 航班價格>
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // 初始化所有 DP 狀態陣列
    vector<long long> dist(n + 1, INF);
    vector<long long> ways(n + 1, 0);
    vector<int> min_f(n + 1, 1e9);
    vector<int> max_f(n + 1, -1);

    // Dijkstra 優先佇列：pair<當前總價格, 節點>
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // 起點 1 的初始化狀態
    dist[1] = 0;
    ways[1] = 1;
    min_f[1] = 0;
    max_f[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // 剪枝：如果拿出來的價格大於已知的最短價格，直接跳過
        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            // 情況 1：發現了更便宜的路線
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;
                pq.push({dist[v], v});
            }
            // 情況 2：發現了價格一樣便宜的替代路線
            else if (dist[u] + w == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
                min_f[v] = min(min_f[v], min_f[u] + 1);
                max_f[v] = max(max_f[v], max_f[u] + 1);
            }
        }
    }

    // 輸出終點 n 的四個查詢結果
    cout << dist[n] << " " << ways[n] << " " << min_f[n] << " " << max_f[n] << "\n";

    return 0;
}