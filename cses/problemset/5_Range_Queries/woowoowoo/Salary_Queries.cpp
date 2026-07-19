#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 儲存查詢的結構
struct Query {
    char type;
    int a, b;
};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> salaries(n + 1);
    vector<int> vals; // 用來做座標壓縮的陣列
    
    // 讀取初始薪水
    for (int i = 1; i <= n; ++i) {
        cin >> salaries[i];
        vals.push_back(salaries[i]);
    }

    // 離線讀取所有查詢
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type >> queries[i].a >> queries[i].b;
        if (queries[i].type == '!') {
            // 單點修改：記錄新出現的薪水
            vals.push_back(queries[i].b);
        } else {
            // 區間查詢：記錄查詢的上下界
            vals.push_back(queries[i].a);
            vals.push_back(queries[i].b);
        }
    }

    // 座標壓縮核心：排序 + 去除重複元素
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    int max_idx = vals.size();

    // 取得某個數值壓縮後的排名 (1-based index)
    auto get_compressed = [&](int x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    };

    // 建立樹狀陣列 (Binary Indexed Tree)
    vector<int> bit(max_idx + 1, 0);

    auto add = [&](int idx, int val) {
        for (; idx <= max_idx; idx += idx & -idx) {
            bit[idx] += val;
        }
    };

    auto query = [&](int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    };

    // 1. 將初始薪水加入樹狀陣列
    for (int i = 1; i <= n; ++i) {
        add(get_compressed(salaries[i]), 1);
    }

    // 2. 依序執行所有查詢
    for (int i = 0; i < q; ++i) {
        if (queries[i].type == '!') {
            int k = queries[i].a;
            int x = queries[i].b;
            // 移除舊薪水
            add(get_compressed(salaries[k]), -1);
            // 更新並加入新薪水
            salaries[k] = x;
            add(get_compressed(salaries[k]), 1);
        } else {
            int a = get_compressed(queries[i].a);
            int b = get_compressed(queries[i].b);
            // 利用前綴和相減得出區間 [a, b] 內的數量
            cout << query(b) - query(a - 1) << "\n";
        }
    }

    return 0;
}