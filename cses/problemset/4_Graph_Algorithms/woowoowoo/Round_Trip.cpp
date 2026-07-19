#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> parent_node;
vector<bool> visited;
int cycle_start = -1, cycle_end = -1;

// 使用 DFS 尋找無向圖中的環
bool dfs(int u, int p) {
    visited[u] = true;
    parent_node[u] = p;

    for (int v : adj[u]) {
        if (v == p) continue; // 不能走回直接父節點

        if (visited[v]) {
            // 找到一個已經訪問過且不是父節點的點，說明有環
            cycle_start = v;
            cycle_end = u;
            return true;
        }

        if (!visited[v]) {
            if (dfs(v, u)) return true;
        }
    }
    return false;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    visited.assign(n + 1, false);
    parent_node.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 圖可能不連通，需要遍歷所有節點
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans;
        ans.push_back(cycle_start);
        
        // 從終點逆向回溯到起點
        for (int v = cycle_end; v != cycle_start; v = parent_node[v]) {
            ans.push_back(v);
        }
        ans.push_back(cycle_start); // 重新放回起點作為閉合環的終點

        // 題目要求正向或反向皆可，為了直觀我們將其反轉
        reverse(ans.begin(), ans.end());

        cout << ans.size() << "\n";
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}