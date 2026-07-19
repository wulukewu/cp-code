#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

// 優先佇列中存儲的狀態：{當前總花費, {節點, 折扣券是否已使用}}
struct State {
    long long cost;
    int u;
    int used;
    
    // 自訂比較運算子，用於 Min-Heap
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 鄰接串列：pair<目標節點, 票價>
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // dist[i][0]: 到達 i 未用券的最短距離；dist[i][1]: 到達 i 已用券的最短距離
    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cost, u, used] = pq.top();
        pq.pop();

        // 懶惰刪除優化
        if (cost > dist[u][used]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (used == 0) {
                // 選擇 1：在這班航班上「不用」折扣券
                if (dist[u][0] + w < dist[v][0]) {
                    dist[v][0] = dist[u][0] + w;
                    pq.push({dist[v][0], v, 0});
                }
                // 選擇 2：在這班航班上「使用」折扣券
                if (dist[u][0] + w / 2 < dist[v][1]) {
                    dist[v][1] = dist[u][0] + w / 2;
                    pq.push({dist[v][1], v, 1});
                }
            } else {
                // 選擇 3：先前已經用過折扣券，此班只能以原價購買
                if (dist[u][1] + w < dist[v][1]) {
                    dist[v][1] = dist[u][1] + w;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    // 最終答案必然是使用過折扣券到達 n 的最短距離
    cout << dist[n][1] << "\n";

    return 0;
}