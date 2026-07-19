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
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // teams[i] 儲存第 i 個學生的隊伍 (0: 未分配, 1: 第一隊, 2: 第二隊)
    vector<int> teams(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        // 如果這個學生還沒有被分配隊伍，代表遇到一個新的連通分量
        if (teams[i] == 0) {
            teams[i] = 1; // 預設新分量的起點為第 1 隊
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (teams[v] == 0) {
                        // 如果朋友還沒分隊，分配到相反的隊伍 (3 - 1 = 2, 3 - 2 = 1)
                        teams[v] = 3 - teams[u];
                        q.push(v);
                    } else if (teams[v] == teams[u]) {
                        // 如果朋友已經在隊伍中，且跟自己同一隊，代表無法二分
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }

    // 順利完成二分圖染色，輸出結果
    for (int i = 1; i <= n; ++i) {
        cout << teams[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}