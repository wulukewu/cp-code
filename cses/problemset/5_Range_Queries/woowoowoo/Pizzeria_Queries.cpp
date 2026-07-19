#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 使用極大值避免影響最小值判斷

int n, q;
vector<long long> treeL;
vector<long long> treeR;

// 單點更新
void update(int p, long long val) {
    int idx = p + 1; // 1-based 的實際座標
    
    // 移至線段樹的葉節點 (0-based 索引)
    for (treeL[p += n] = val - idx, treeR[p] = val + idx; p > 1; p >>= 1) {
        treeL[p >> 1] = min(treeL[p], treeL[p ^ 1]);
        treeR[p >> 1] = min(treeR[p], treeR[p ^ 1]);
    }
}

// 查詢左區間 [l, r) 的最小值
long long queryL(int l, int r) {
    long long res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, treeL[l++]);
        if (r & 1) res = min(res, treeL[--r]);
    }
    return res;
}

// 查詢右區間 [l, r) 的最小值
long long queryR(int l, int r) {
    long long res = INF;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, treeR[l++]);
        if (r & 1) res = min(res, treeR[--r]);
    }
    return res;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    treeL.assign(2 * n, INF);
    treeR.assign(2 * n, INF);

    // 讀取初始披薩價格並建立線段樹的葉節點
    for (int i = 0; i < n; ++i) {
        long long price;
        cin >> price;
        treeL[n + i] = price - (i + 1);
        treeR[n + i] = price + (i + 1);
    }

    // 由下而上建立線段樹內部節點 (O(N))
    for (int i = n - 1; i > 0; --i) {
        treeL[i] = min(treeL[i << 1], treeL[i << 1 | 1]);
        treeR[i] = min(treeR[i << 1], treeR[i << 1 | 1]);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            long long x;
            cin >> k >> x;
            // 更新 k 點的價格，k 轉為 0-based 索引
            update(k - 1, x);
        } else {
            int k;
            cin >> k;
            
            // 左側成本: 範圍 [0, k) 的 treeL 最小值 + k
            long long costL = queryL(0, k) + k;
            
            // 右側成本: 範圍 [k-1, n) 的 treeR 最小值 - k
            long long costR = queryR(k - 1, n) - k;
            
            cout << min(costL, costR) << "\n";
        }
    }

    return 0;
}