#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<int> adj[1 << 10]; // 預處理每個 mask 可以轉移到的 next_mask 列表

// DFS 預處理狀態轉移
void generate_transitions(int i, int mask, int next_mask) {
    if (i == n) {
        adj[mask].push_back(next_mask);
        return;
    }
    
    // 如果當前格已經被上一列的橫塊填了 (mask 的第 i 位為 1)
    if (mask & (1 << i)) {
        // 當前格不能放東西，下一列的這一格必定是空的 (0)
        generate_transitions(i + 1, mask, next_mask);
    } else {
        // 情況 1: 嘗試往右放一個 1x2 的橫塊，會塞到下一列的這一格 (next_mask 的第 i 位變 1)
        generate_transitions(i + 1, mask, next_mask | (1 << i));
        
        // 情況 2: 嘗試往下放一個 2x1 的豎塊
        // 條件：下一格 (i+1) 也在邊界內，且當前列的下一格也是空的
        if (i + 1 < n && !(mask & (1 << (i + 1)))) {
            generate_transitions(i + 2, mask, next_mask);
        }
    }
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    int num_states = 1 << n;

    // 1. 預處理所有合法的狀態轉移
    for (int mask = 0; mask < num_states; ++mask) {
        generate_transitions(0, mask, 0);
    }

    // 2. 滾動陣列優化空間：dp[mask] 表示當前列狀態為 mask 的方法數
    vector<int> dp(num_states, 0);
    dp[0] = 1; // 初始狀態：第 0 列之前沒有任何橫塊突出來

    // 3. 逐列進行動態規劃
    for (int col = 0; col < m; ++col) {
        vector<int> next_dp(num_states, 0);
        for (int mask = 0; mask < num_states; ++mask) {
            if (dp[mask] == 0) continue; // 剪枝
            
            for (int next_mask : adj[mask]) {
                next_dp[next_mask] += dp[mask];
                if (next_dp[next_mask] >= MOD) {
                    next_dp[next_mask] -= MOD;
                }
            }
        }
        dp = move(next_dp);
    }

    // 最終答案：最後一列結束後，不能有任何橫塊突出到根本不存在的下一列 (即 mask 必須為 0)
    cout << dp[0] << "\n";

    return 0;
}