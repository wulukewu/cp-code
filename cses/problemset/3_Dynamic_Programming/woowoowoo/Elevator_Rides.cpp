#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    // dp[mask] 儲存 pair<int, long long> -> {最少趟數, 最後一趟目前的總重量}
    // 總狀態數為 2^n
    int num_states = 1 << n;
    vector<pair<int, long long>> dp(num_states);

    // 初始狀態：沒有人搭乘時，需要 1 趟，且最後一趟重量為 0
    dp[0] = {1, 0};

    // 遍歷所有狀態
    for (int mask = 0; mask < num_states; ++mask) {
        if (dp[mask].first == 0) continue; // 剪枝：未達到的狀態跳過

        int current_rides = dp[mask].first;
        long long current_weight = dp[mask].second;

        // 嘗試加入每一個人
        for (int i = 0; i < n; ++i) {
            // 如果第 i 個人還沒在當前狀態中
            if (!(mask & (1 << i))) {
                int next_rides = current_rides;
                long long next_weight = current_weight + w[i];

                // 如果超重，必須新開一趟
                if (next_weight > x) {
                    next_rides++;
                    next_weight = w[i];
                }

                int next_mask = mask | (1 << i);
                pair<int, long long> next_state = {next_rides, next_weight};

                // 如果還沒被初始化，或者找到了更優的解（趟數更少，或趟數相同但最後一趟更輕）
                if (dp[next_mask].first == 0 || next_state < dp[next_mask]) {
                    dp[next_mask] = next_state;
                }
            }
        }
    }

    // 最終答案即為所有人都在電梯裡（mask 全為 1）的最少趟數
    cout << dp[num_states - 1].first << "\n";

    return 0;
}