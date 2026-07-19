#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<int> freq(26, 0);
    int max_freq = 0;

    // 統計字元頻率並找出最大頻率
    for (char c : s) {
        freq[c - 'A']++;
        if (freq[c - 'A'] > max_freq) {
            max_freq = freq[c - 'A'];
        }
    }

    // 判斷是否無解
    if (max_freq > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    string ans;
    ans.reserve(n); // 預留空間，避免動態擴展浪費時間
    int prev = -1;  // 記錄前一個填入的字元，初始為 -1

    for (int i = 0; i < n; ++i) {
        int L = n - i;        // 剩餘的字元總數
        int limit = L / 2;    // 當前安全頻率上限
        int forced = -1;

        // 1. 檢查是否有字元到達頻率極限，成為被迫選擇
        for (int j = 0; j < 26; ++j) {
            if (freq[j] > limit) {
                forced = j;
                break;
            }
        }

        if (forced != -1) {
            ans += (char)('A' + forced);
            freq[forced]--;
            prev = forced;
        } else {
            // 2. 如果沒有被迫選擇，尋找字典序最小且合法的字元
            for (int j = 0; j < 26; ++j) {
                if (freq[j] > 0 && j != prev) {
                    ans += (char)('A' + j);
                    freq[j]--;
                    prev = j;
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}