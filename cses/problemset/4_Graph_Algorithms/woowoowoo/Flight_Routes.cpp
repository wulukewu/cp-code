#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // 鄰接串列：pair<目標節點, 權重>
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // 為每個節點建立一個最大堆疊，用來記錄該點目前的前 k 短路徑
    vector<priority_queue<long long>> best_costs(n + 1);
    
    // Dijkstra 優先佇列：pair<當前總代價, 節點>，使用 Min-Heap 確保每次取出最小代價
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // 初始化起點 1
    pq.push({0, 1});
    best_costs[1].push(0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // 剪枝優化：如果當前取出的代價比 u 點目前第 k 短的代價還要大，則這個狀態不可能更新任何鄰居
        if (d > best_costs[u].top()) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            long long next_d = d + w;

            // 情況 1：v 的前 k 短路徑還沒收集滿
            if ((int)best_costs[v].size() < k) {
                best_costs[v].push(next_d);
                pq.push({next_d, v});
            }
            // 情況 2：已收集滿 k 條，若新路徑比這 k 條裡面最長的那條還要短，則踢掉最長並更新
            else if (next_d < best_costs[v].top()) {
                best_costs[v].pop();
                best_costs[v].push(next_d);
                pq.push({next_d, v});
            }
        }
    }

    // 收集終點 n 的前 k 短路
    vector<long long> ans;
    while (!best_costs[n].empty()) {
        ans.push_back(best_costs[n].top());
        best_costs[n].pop();
    }

    // 因為 max-heap 彈出的順序是由大到小，翻轉後即為題目要求的小到大排序
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < k; ++i) {
        cout << ans[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}