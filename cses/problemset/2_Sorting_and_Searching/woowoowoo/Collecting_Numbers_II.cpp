#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> arr(n + 1);
    vector<int> pos(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i; // 記錄每個數字的原始位置
    }

    // 計算初始所需的回合數
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (pos[i] > pos[i + 1]) {
            ans++;
        }
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        int v1 = arr[a];
        int v2 = arr[b];

        if (v1 == v2) {
            // 交換相同數字不影響結果
            cout << ans << "\n";
            continue;
        }

        // 收集受影響的數對 (x, x+1) 的 x
        // 使用 set 可以完美解決當 |v1 - v2| == 1 時造成的重複檢查問題
        set<int> check_vals;
        if (v1 > 1) check_vals.insert(v1 - 1);
        if (v1 < n) check_vals.insert(v1);
        if (v2 > 1) check_vals.insert(v2 - 1);
        if (v2 < n) check_vals.insert(v2);

        // 1. 扣除交換前的貢獻
        for (int x : check_vals) {
            if (pos[x] > pos[x + 1]) {
                ans--;
            }
        }

        // 2. 執行交換，更新陣列與位置記錄
        swap(arr[a], arr[b]);
        pos[v1] = b;
        pos[v2] = a;

        // 3. 加上交換後的貢獻
        for (int x : check_vals) {
            if (pos[x] > pos[x + 1]) {
                ans++;
            }
        }

        // $O(1)$ 輸出當前答案
        cout << ans << "\n";
    }

    return 0;
}