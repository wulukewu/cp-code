#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;

    // 使用 pair 來儲存 {數值, 原始位置}
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i + 1; // 題目要求 1-based index
    }

    // 依照數值大小進行排序
    sort(arr.begin(), arr.end());

    // 雙指標夾擠
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        
        if (sum == x) {
            cout << arr[left].second << " " << arr[right].second << "\n";
            return 0;
        } else if (sum < x) {
            left++;  // 總和太小，左指標右移
        } else {
            right--; // 總和太大，右指標左移
        }
    }

    // 遍歷完畢仍未找到
    cout << "IMPOSSIBLE\n";

    return 0;
}