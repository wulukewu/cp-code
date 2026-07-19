#include <iostream>
#include <vector>

using namespace std;

// 定義邊的結構
struct Edge {
    int to;
    int id; // 邊的唯一編號，用來快速標記是否走過
};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    // 讀取圖並計算度數
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++;
        degree[v]++;
    }

    // 條件 1：檢查所有節點的度數是否都是偶數
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> path;           // 儲存尤拉迴路徑
    vector<char> used(m, 0);    // 記錄每一條邊是否已經被走過 (使用 char 避免 vector<bool> 的額外負擔)
    vector<int> st;             // 模擬 DFS 的 Stack
    
    st.push_back(1);            // 從節點 1 (郵局) 開始

    // Hierholzer's Algorithm (迭代版)
    while (!st.empty()) {
        int u = st.back();
        bool found_edge = false;

        // 嘗試找出當前節點一條未使用的邊
        while (!adj[u].empty()) {
            Edge e = adj[u].back();
            adj[u].pop_back(); // 直接從鄰接串列中移除，確保 O(V+E) 的效率
            
            if (!used[e.id]) {
                used[e.id] = 1;
                st.push_back(e.to); // 走到下一個節點
                found_edge = true;
                break;
            }
        }

        // 如果當前節點已經沒有未使用的邊了，代表它陷入死胡同，將其加入路徑
        if (!found_edge) {
            path.push_back(u);
            st.pop_back();
        }
    }

    // 條件 2：檢查連通性
    // 合法的尤拉迴路，其節點總數必定剛好是 邊數(m) + 1。
    // 如果長度不對，代表有其他的邊在另一個不相連的連通分量裡。
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        // Hierholzer 找出的路徑是反向的，將其反轉輸出 (這題正反輸出皆可，但反轉才是標準尤拉迴路順序)
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << (i == 0 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}