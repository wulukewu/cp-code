#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// dp[idx][last_digit + 1][is_leading_zero]
// last_digit 範圍是 -1 ~ 9，所以 +1 對應到索引 0 ~ 10
long long dp[20][12][2];
string num_str;

long long dfs(int idx, int last_digit, bool is_tight, bool is_leading_zero) {
    // 順利填完所有位數，代表找到 1 個合法解
    if (idx == num_str.length()) {
        return 1;
    }

    // 只有在不受邊界限制 (is_tight = false) 時，才能使用記憶化陣列
    if (!is_tight && dp[idx][last_digit + 1][is_leading_zero] != -1) {
        return dp[idx][last_digit + 1][is_leading_zero];
    }

    long long ans = 0;
    // 根據當前是否緊貼上限，決定能填的最大數字
    int limit = is_tight ? (num_str[idx] - '0') : 9;

    for (int d = 0; d <= limit; ++d) {
        // 如果不是前導零，且當前想填的數字與上一個數字相同，則為不合法轉移
        if (!is_leading_zero && d == last_digit) {
            continue;
        }

        // 判斷下一個狀態是否仍然是前導零
        bool next_leading_zero = is_leading_zero && (d == 0);
        // 判斷下一個狀態是否需要緊貼上限
        bool next_tight = is_tight && (d == limit);

        ans += dfs(idx + 1, next_leading_zero ? -1 : d, next_tight, next_leading_zero);
    }

    if (!is_tight) {
        dp[idx][last_digit + 1][is_leading_zero] = ans;
    }
    return ans;
}

long long solve(long long x) {
    if (x < 0) return 0;
    if (x == 0) return 1; // 數字 0 獨立算 1 個合法解

    num_str = to_string(x);
    memset(dp, -1, sizeof(dp));
    
    // 從第 0 位開始填，上一個數字為 -1，一開始有邊界限制 (true)，且目前是前導零 (true)
    return dfs(0, -1, true, true);
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    if (cin >> a >> b) {
        if (a == 0) {
            cout << solve(b) << "\n";
        } else {
            cout << solve(b) - solve(a - 1) << "\n";
        }
    }

    return 0;
}