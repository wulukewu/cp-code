#include <iostream>
#include <map>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    // 儲存前綴和出現次數的 Map
    // 使用 std::map (O(log n)) 而非 std::unordered_map (O(1))，
    // 是為了避免在競賽中遭遇惡意測資引發 Hash Collision 導致 TLE。
    map<long long, int> prefix_counts;
    
    // 初始化：空前綴的總和為 0，出現次數 1
    prefix_counts[0] = 1;

    long long current_sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        current_sum += val;

        // 尋找前面是否有前綴和等於 current_sum - x
        auto it = prefix_counts.find(current_sum - x);
        if (it != prefix_counts.end()) {
            ans += it->second;
        }

        // 將當前的前綴和加入記錄中
        prefix_counts[current_sum]++;
    }

    cout << ans << "\n";

    return 0;
}