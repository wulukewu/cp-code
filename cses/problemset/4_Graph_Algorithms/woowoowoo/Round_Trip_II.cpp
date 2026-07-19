#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited; // 0: 未訪問, 1: 訪問中, 2: 已完成
vector<int> parent_node;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u) {
    visited[u] = 1; // 標記為訪問中

    for (int v : adj[u]) {
        if (visited[v] == 0) {
            parent_node[v] = u;
            if (dfs(v)) return true;
        } 
        // 發現撞回正在訪問中的節點，找到有向環！
        else if (visited[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }

    visited[u] = 2; // 標記為已完成
    return false;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    visited.assign(n + 1, 0);
    parent_node.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 因為圖可能不連通，對所有未訪問的點跑 DFS
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            if (dfs(i)) break;
        }
    }

    // 若沒有找到任何環
    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        
        // 從終點逆向追溯回起點
        for (int curr = cycle_end; curr != cycle_start; curr = parent_node[curr]) {
            cycle.push_back(curr);
        }
        cycle.push_back(cycle_start); // 閉合環（起終點相同）

        // 因為是逆向追溯，翻轉後即為正向的拜訪順序
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int i = 0; i < (int)cycle.size(); ++i) {
            cout << cycle[i] << (i == (int)cycle.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}