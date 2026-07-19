#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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

    // 儲存每首歌曲「最後一次出現」的索引位置
    map<int, int> last_pos;
    
    int max_len = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        int song = arr[right];

        // 如果這首歌出現過，且它出現在當前視窗的範圍內
        if (last_pos.count(song) && last_pos[song] >= left) {
            // 將左指標移動到該歌曲上次出現位置的下一個位置，藉此將重複的歌踢出視窗
            left = last_pos[song] + 1;
        }

        // 更新這首歌最後出現的位置為當前的 right
        last_pos[song] = right;

        // 計算並更新當前不重複子序列的最大長度
        max_len = max(max_len, right - left + 1);
    }

    cout << max_len << "\n";

    return 0;
}