#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 儲存視窗內每個數字出現的頻率
    map<int, int> freq;
    
    int left = 0;
    long long total_subarrays = 0;

    for (int right = 0; right < n; ++right) {
        // 將右指標的數字加入視窗
        freq[arr[right]]++;

        // 如果視窗內的相異數字超過 k 種，縮減視窗直到合法
        while ((int)freq.size() > k) {
            freq[arr[left]]--;
            // 如果該數字在視窗內的頻率降為 0，將其從 Map 中徹底移除
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }

        // 累加以當前 right 為結尾的所有合法子陣列數量
        total_subarrays += (right - left + 1);
    }

    cout << total_subarrays << "\n";

    return 0;
}