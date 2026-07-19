#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// 測資的數值可能達到 10^9，累加後極可能超過 int 上限，必須使用 long long。
// 這裡設定一個極小值作為初始的 max_sum
const long long INF = 1e18;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    // 建立前綴和陣列，大小開 n+1，pref[0] 預設為 0
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        pref[i] = pref[i - 1] + val;
    }

    long long max_sum = -INF;
    deque<int> dq; // 單調佇列，儲存前綴和的「索引」

    // 結尾位置 i 最少要從 a 開始，這樣才能保證子陣列長度 >= a
    for (int i = a; i <= n; ++i) {
        int new_j = i - a; // 即將進入視窗的最新左端點

        // 1. 維護單調遞增性：剔除隊尾比新元素大的舊值
        while (!dq.empty() && pref[dq.back()] >= pref[new_j]) {
            dq.pop_back();
        }
        dq.push_back(new_j);

        // 2. 剔除已經離開視窗的過期索引
        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }

        // 3. 隊首即為合法範圍內 [i-b, i-a] 最小的前綴和索引
        max_sum = max(max_sum, pref[i] - pref[dq.front()]);
    }

    cout << max_sum << "\n";

    return 0;
}