#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 儲存每個數字「最後一次出現」的索引位置
    map<int, int> last_pos;
    
    long long total_subarrays = 0; // 答案可能超過 int 範圍，必須用 long long
    int left = 0;

    for (int right = 0; right < n; ++right) {
        int val = arr[right];

        // 如果這個數字出現過，且它出現在當前視窗的範圍內
        if (last_pos.count(val) && last_pos[val] >= left) {
            // 將左指標移動到該數字上次出現位置的下一個位置
            left = last_pos[val] + 1;
        }

        // 更新該數字最後出現的位置為當前的 right
        last_pos[val] = right;

        // 累加「以 right 結尾」的所有合法子陣列數量
        total_subarrays += (right - left + 1);
    }

    cout << total_subarrays << "\n";

    return 0;
}