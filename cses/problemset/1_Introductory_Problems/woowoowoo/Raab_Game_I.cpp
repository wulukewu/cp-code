#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // 條件 1：兩人的得分總和不可能超過總卡牌數 n
    if (a + b > n) {
        cout << "NO\n";
        return;
    }

    // 條件 2：只要有得分產生，雙方都必須有得分 (不可能有人全輸卻有人拿分)
    if ((a == 0 && b > 0) || (b == 0 && a > 0)) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<int> p1, p2;
    p1.reserve(n);
    p2.reserve(n);

    int k = n - a - b;

    // 1. 構造平手局：雙方出 1 到 k
    for (int i = 1; i <= k; ++i) {
        p1.push_back(i);
        p2.push_back(i);
    }

    // 2. 構造玩家 1 獲勝的 a 局
    // 玩家 1 出剩餘牌裡最大的 a 張：k + b + 1 ~ n
    // 玩家 2 出剩餘牌裡最小的 a 張：k + 1 ~ k + a
    for (int i = 1; i <= a; ++i) {
        p1.push_back(k + b + i);
        p2.push_back(k + i);
    }

    // 3. 構造玩家 2 獲勝的 b 局
    // 玩家 1 出剩餘牌裡最小的 b 張：k + 1 ~ k + b
    // 玩家 2 出剩餘牌裡最大的 b 張：k + a + 1 ~ n
    for (int i = 1; i <= b; ++i) {
        p1.push_back(k + i);
        p2.push_back(k + a + i);
    }

    // 輸出玩家 1 的出牌順序
    for (int i = 0; i < n; ++i) {
        cout << p1[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    // 輸出玩家 2 的出牌順序
    for (int i = 0; i < n; ++i) {
        cout << p2[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}