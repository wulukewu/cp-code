#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> adj;
vector<int> dp_memo;
vector<int> next_node;

// 記憶化搜索 DFS
int solve(int u) {
    // 走到終點，返回 1 (包含終點本身)
    if (u == n) {
        return 1;
    }
    // 如果已經計算過，直接返回結果
    if (dp_memo[u] != -1) {
        return dp_memo[u];
    }

    int max_cities = -INF;
    
    for (int v : adj[u]) {
        int res = solve(v);
        if (res > 0 && res + 1 > max_cities) {
            max_cities = res + 1;
            next_node[u] = v; // 記錄最長路徑的下一步
        }
    }

    return dp_memo[u] = max_cities;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    dp_memo.assign(n + 1, -1);
    next_node.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = solve(1);

    // 如果 ans < 0，代表從 1 無法到達 n
    if (ans < 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans << "\n";
        
        // 沿著 next_node 陣列還原整條最長路徑
        vector<int> path;
        int curr = 1;
        while (curr != 0) {
            path.push_back(curr);
            curr = next_node[curr];
        }

        for (int i = 0; i < ans; ++i) {
            cout << path[i] << (i == ans - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}