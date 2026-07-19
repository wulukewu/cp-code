#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

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

    // 將陣列排序，讓相同的數字聚集在一起，方便以 O(n) 計算頻率
    sort(arr.begin(), arr.end());

    long long ans = 1;
    long long current_count = 1;

    // 掃描陣列統計每個數字的頻率，並套用組合數學公式
    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            current_count++;
        } else {
            // 遇到不同的數字時，將前一個數字的 (頻率 + 1) 乘進總和中
            ans = (ans * (current_count + 1)) % MOD;
            current_count = 1; // 重置計數器給下一個數字
        }
    }
    
    // 不要忘記把最後一種數字的選擇數乘進去
    ans = (ans * (current_count + 1)) % MOD;

    // 扣除掉「什麼數字都沒選」的空集合 (空子序列)
    // 加上 MOD 再取餘數，是為了避免 ans 為 0 時減 1 產生負數
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << "\n";

    return 0;
}