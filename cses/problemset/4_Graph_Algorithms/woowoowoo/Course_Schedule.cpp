#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++; // 統計每個節點的入度
    }

    // 將所有入度為 0 的節點加入佇列
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;
    order.reserve(n); // 預先分配空間優化效能

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            // 當入度降為 0，代表先修條件皆已滿足
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 如果排序後的節點數不等於 n，代表圖中有環，無法完成拓撲排序
    if ((int)order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << order[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}