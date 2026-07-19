#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // t: 每個行星的傳送目標
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // ans: 每個行星的總步數
    // state: 0 = 未走訪, 1 = 目前路徑正在走訪, 2 = 已完成計算
    vector<int> ans(n + 1, 0);
    vector<int> state(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        // 如果這個節點已經計算過了，直接跳過
        if (ans[i] != 0) continue;

        vector<int> path;
        int u = i;

        // 一直往前走，直到撞到目前路徑的節點 (環) 或已經算過答案的節點
        while (ans[u] == 0 && state[u] == 0) {
            state[u] = 1;
            path.push_back(u);
            u = t[u];
        }

        // 情況 1：撞到了目前這趟 DFS 路徑中的節點，代表發現了新的環
        if (state[u] == 1) {
            int cycle_len = 0;
            // 從路徑的後面找回去，計算環的長度
            for (int j = (int)path.size() - 1; j >= 0; --j) {
                cycle_len++;
                if (path[j] == u) break;
            }

            // 把環上所有節點的答案都設為環的長度
            int curr = u;
            for (int j = 0; j < cycle_len; ++j) {
                ans[curr] = cycle_len;
                curr = t[curr];
            }
        }

        // 情況 2：逆向回推樹枝上節點的答案
        // 如果節點已經有答案（它是環的一部分），就不會被覆蓋；
        // 如果沒有答案，它的步數就是下一個節點步數 + 1
        for (int j = (int)path.size() - 1; j >= 0; --j) {
            int node = path[j];
            state[node] = 2; // 標記為已徹底完成計算
            if (ans[node] == 0) {
                ans[node] = ans[t[node]] + 1;
            }
        }
    }

    // 輸出答案
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}