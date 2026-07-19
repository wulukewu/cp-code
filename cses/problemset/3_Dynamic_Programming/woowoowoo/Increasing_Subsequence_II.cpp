#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

// 芬威克樹 (樹狀陣列) 實作
struct FenwickTree {
    int size;
    vector<long long> tree;

    FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    // 單點修改：在位置 i 加上 val
    void add(int i, long long val) {
        for (; i <= size; i += i & -i) {
            tree[i] = (tree[i] + val) % MOD;
        }
    }

    // 區間查詢：查詢 [1, i] 的前綴和
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum = (sum + tree[i]) % MOD;
        }
        return sum;
    }
};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> x(n);
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        vals[i] = x[i];
    }

    // 1. 座標壓縮 (離散化)
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int k = vals.size();
    FenwickTree bit(k);

    long long total_subsequences = 0;

    // 2. 動態規劃與 BIT 轉移
    for (int i = 0; i < n; ++i) {
        // 找到當前元素在離散化後的 1-based 排名
        int rank = lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin() + 1;

        // 查詢前面所有比自己小的元素所貢獻的 DP 值總和
        // 加上 1 代表自己單獨形成一個長度為 1 的子序列
        long long current_dp = (1 + bit.query(rank - 1)) % MOD;

        // 累加到最終答案
        total_subsequences = (total_subsequences + current_dp) % MOD;

        // 更新樹狀陣列
        bit.add(rank, current_dp);
    }

    cout << total_subsequences << "\n";

    return 0;
}