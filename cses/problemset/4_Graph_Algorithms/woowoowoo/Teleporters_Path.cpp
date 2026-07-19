#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> in_deg(n + 1, 0);
    vector<int> out_deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out_deg[u]++;
        in_deg[v]++;
    }

    // 條件 1：檢查所有節點的度數條件是否合法
    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            // 起點：出度必須比入度多 1
            if (out_deg[i] - in_deg[i] != 1) possible = false;
        } else if (i == n) {
            // 終點：入度必須比出度多 1
            if (in_deg[i] - out_deg[i] != 1) possible = false;
        } else {
            // 中間節點：出度與入度必須相等
            if (in_deg[i] != out_deg[i]) possible = false;
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    vector<int> st; // 模擬 DFS 的 Stack
    st.push_back(1);

    // Hierholzer's Algorithm (迭代版)
    while (!st.empty()) {
        int u = st.back();

        // 只要還有未走過的邊，就繼續往下走
        if (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back(); // O(1) 移除已走過的邊
            st.push_back(v);
        } 
        // 無路可走（陷入死胡同），將該節點加入路徑中
        else {
            path.push_back(u);
            st.pop_back();
        }
    }

    // 條件 2：檢查連通性
    // 合法的尤拉路徑，其經過的節點總數必定剛好是 邊數(m) + 1。
    // 如果長度不對，代表圖中存在其他不相連的連通環。
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        // Hierholzer 找出的路徑是反向的，反轉後即為正確答案
        reverse(path.begin(), path.end());
        
        for (int i = 0; i <= m; ++i) {
            cout << path[i] << (i == m ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}