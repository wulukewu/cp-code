#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<string> ans(n, string(m, ' '));

    // 由上到下，由左至右貪心填色
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // 嘗試 A, B, C, D 四種顏色
            for (char c : {'A', 'B', 'C', 'D'}) {
                if (c == grid[i][j]) continue; // 條件 1：不能與原本的字母相同
                if (i > 0 && c == ans[i - 1][j]) continue; // 條件 2：不能與上方的字母相同
                if (j > 0 && c == ans[i][j - 1]) continue; // 條件 3：不能與左方的字母相同
                
                // 找到符合的字母，填入並跳出迴圈
                ans[i][j] = c;
                break;
            }
        }
    }

    // 輸出結果
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}