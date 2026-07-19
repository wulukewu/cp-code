#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    long long weight;
};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // 距離陣列初始化為 0，等同於同時從所有點出發，解決圖不連通的問題
    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, 0);
    
    int last_updated_node = -1;

    // 執行 n 次迭代 (第 n 次用於抓出負權環)
    for (int i = 1; i <= n; ++i) {
        last_updated_node = -1;
        for (const auto& e : edges) {
            if (dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
                parent[e.v] = e.u;
                last_updated_node = e.v; // 記錄最後被更新的點
            }
        }
    }

    // 如果第 n 次迭代沒有任何點被更新，代表沒有負權環
    if (last_updated_node == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        // 往回追溯 n 次，確保進入環的內部
        int cycle_node = last_updated_node;
        for (int i = 0; i < n; ++i) {
            cycle_node = parent[cycle_node];
        }

        // 開始收集環上的節點
        vector<int> cycle;
        for (int curr = cycle_node;; curr = parent[curr]) {
            cycle.push_back(curr);
            if (curr == cycle_node && cycle.size() > 1) {
                break;
            }
        }

        // 因為是透過 parent 逆向追蹤，需要反轉陣列以得到正向的環路徑
        reverse(cycle.begin(), cycle.end());

        for (int i = 0; i < (int)cycle.size(); ++i) {
            cout << cycle[i] << (i == (int)cycle.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}