#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 特殊處理 n=1 的情況
    if (n == 1) {
        cout << "01\n";
        return 0;
    }

    // 計算 n-1 位元的遮罩，用來把長度超過 n-1 的左側位元消除
    int mask = (1 << (n - 1)) - 1;

    // next_edge[u] 記錄節點 u 接下來要嘗試走哪條邊 (0 或 1)
    // 當值為 2 時代表兩條邊都走過了
    vector<int> next_edge(1 << (n - 1), 0);
    
    // 模擬 DFS 堆疊：儲存 pair {當前節點, 走到這節點所使用的邊 (0 或 1)}
    vector<pair<int, int>> st;
    st.push_back({0, -1}); // 從全 0 的節點出發，初始邊設為 -1 代表起點
    
    string path = "";

    // 迭代版 Hierholzer's Algorithm
    while (!st.empty()) {
        int u = st.back().first;

        // 如果這個節點還有未走的邊
        if (next_edge[u] < 2) {
            int bit = next_edge[u]++;             // 取得邊的值 (0 或 1) 並將指標加 1
            int v = ((u << 1) | bit) & mask;      // 狀態轉移：左移一位，補上新位元，並套用遮罩
            st.push_back({v, bit});               // 走到下一個節點
        } 
        // 該節點的出邊都走完了，退堆疊並將「進入該節點的邊」加入尤拉路徑中
        else {
            int edge_bit = st.back().second;
            st.pop_back();
            if (edge_bit != -1) {
                path += (char)('0' + edge_bit);
            }
        }
    }

    // Hierholzer 找出的路徑是反向的，將其反轉
    reverse(path.begin(), path.end());

    // 最終答案 = 前綴 (n-1 個 '0') + 尤拉路徑
    string ans = string(n - 1, '0') + path;

    cout << ans << "\n";

    return 0;
}