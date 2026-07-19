#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> x(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        total_sum += x[i];
    }

    // dp[i] 在滾動更新中代表當前區間長度下，以 i 為起點的最大得分差
    vector<long long> dp(n);

    // 基礎狀態：區間長度為 1
    for (int i = 0; i < n; ++i) {
        dp[i] = x[i];
    }

    // 區間長度從 2 遞增到 n
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i] = max(x[i] - dp[i + 1], x[j] - dp[i]);
        }
    }

    // 計算第一個玩家的最大絕對得分
    long long max_score_p1 = (total_sum + dp[0]) / 2;
    cout << max_score_p1 << "\n";

    return 0;
}