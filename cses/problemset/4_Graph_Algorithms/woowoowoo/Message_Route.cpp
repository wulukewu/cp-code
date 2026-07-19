#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // parent[i] 記錄是哪一台電腦連到 i 的，同時 0 代表尚未訪問
    vector<int> parent(n + 1, 0);
    queue<int> q;

    // 起點是 1
    q.push(1);
    parent[1] = -1; // 標記起點的父節點為特殊值，避免被重複訪問

    bool possible = false;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == n) {
            possible = true;
            break;
        }

        for (int v : adj[u]) {
            if (parent[v] == 0) { // 如果 v 還沒有被訪問過
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
    } else {
        // 從終點 n 逆向追蹤回起點 1
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        
        // 反轉路徑使其符合從 1 到 n 的順序
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (int i = 0; i < (int)path.size(); ++i) {
            cout << path[i] << (i == (int)path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}