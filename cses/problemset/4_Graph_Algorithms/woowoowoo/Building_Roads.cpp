#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;

// 使用輕量化的 DFS 找出同一個連通分量的所有節點
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 用來儲存每個連通分量的其中一個代表節點
    vector<int> representatives;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }

    // 需要建的道路數為 連通分量數 - 1
    int ans = representatives.size() - 1;
    cout << ans << "\n";

    // 依序將相鄰的連通分量代表節點串接起來
    for (int i = 0; i < ans; ++i) {
        cout << representatives[i] << " " << representatives[i + 1] << "\n";
    }

    return 0;
}