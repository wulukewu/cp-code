#include <iostream>
#include <vector>

using namespace std;

// 因為 k <= 10^9，2^30 = 1,073,741,824 > 10^9，所以倍增表開到 30 層即可
const int MAX_J = 30;

// 將 up 表開在全域或使用二維 vector，這裡為了最大化 I/O 與快取效能，
// 將連續的行星維度擺在內層：up[MAX_J][N]
int up[MAX_J][200005];

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    // 初始化第 0 層（跳 2^0 = 1 步的目標）
    for (int i = 1; i <= n; ++i) {
        cin >> up[0][i];
    }

    // 建立倍增表
    for (int j = 1; j < MAX_J; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }

    // 處理每筆查詢
    while (q--) {
        int x, k;
        cin >> x >> k;

        // 利用二進位拆解 k 進行跳躍
        for (int j = 0; j < MAX_J; ++j) {
            if ((k >> j) & 1) {
                x = up[j][x];
            }
        }
        cout << x << "\n";
    }

    return 0;
}