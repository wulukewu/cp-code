#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18; // 定義一個極大的無窮大值

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 使用鄰接串列存儲圖，pair<目標節點, 權重>
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Dijkstra 初始化
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;
    
    // 優先佇列：存儲 pair<目前距離, 節點>，並使用 greater 來確保取出最小值
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 如果取出的距離大於已知的最短距離，跳過（Lazy Deletion）
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // 鬆弛操作 (Relaxation)
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // 輸出結果
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}