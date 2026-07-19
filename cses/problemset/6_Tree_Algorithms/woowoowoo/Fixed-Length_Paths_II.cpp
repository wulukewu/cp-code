#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool removed_node[MAXN];
int sz[MAXN];

int n, k1, k2;
long long ans = 0;

// cnt[d] 代表前面已經處理過的子樹中，深度為 d 的節點數量
int cnt[MAXN];
// pref[d] 為 cnt 的前綴和陣列
int pref[MAXN];
// cur[d] 用來暫存「當前」這棵子樹中，深度為 d 的節點數量
int cur[MAXN];

// 1. 計算子樹大小
void get_sizes(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed_node[v]) {
            get_sizes(v, u);
            sz[u] += sz[v];
        }
    }
}

// 2. 尋找重心
int get_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p && !removed_node[v] && sz[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}

// 3. 獲取子樹的最大深度 (並以 k2 為上限剪枝)
int get_max_depth(int u, int p, int depth) {
    if (depth > k2) return k2;
    int mx = depth;
    for (int v : adj[u]) {
        if (v != p && !removed_node[v]) {
            mx = max(mx, get_max_depth(v, u, depth + 1));
        }
    }
    return mx;
}

// 4. 統計當前子樹中各深度的節點數
void get_cur(int u, int p, int depth) {
    if (depth > k2) return;
    cur[depth]++;
    for (int v : adj[u]) {
        if (v != p && !removed_node[v]) {
            get_cur(v, u, depth + 1);
        }
    }
}

// 重心剖分主程式
void build(int u) {
    get_sizes(u, 0);
    int centroid = get_centroid(u, 0, sz[u]);

    // 收集所有有效子樹及其最大深度
    vector<pair<int, int>> children;
    for (int v : adj[centroid]) {
        if (!removed_node[v]) {
            int mx_d = get_max_depth(v, centroid, 1);
            mx_d = min(mx_d, k2); // 深度超過 k2 沒意義
            children.push_back({mx_d, v});
        }
    }

    // 核心優化：依照最大深度由小到大排序，避免前綴和更新的時間複雜度退化
    sort(children.begin(), children.end());

    cnt[0] = 1;
    pref[0] = 1;
    int current_max_depth = 0; // 記錄前綴和陣列目前有效建構到的最大深度

    for (auto& child : children) {
        int mx_d = child.first;
        int v = child.second;

        // 收集當前子樹的節點深度分佈
        get_cur(v, centroid, 1);

        // 查詢符合長度限制的路徑數量 (O(1) 區間查詢)
        for (int d = 1; d <= mx_d; ++d) {
            if (cur[d] == 0) continue;
            
            // 計算我們需要尋找的合法深度區間 [L, R]
            int L = max(0, k1 - d);
            int R = k2 - d;
            
            if (L <= R) {
                // R 不能超過目前記錄的最大深度
                R = min(R, current_max_depth);
                if (L <= R) {
                    int sum = pref[R] - (L > 0 ? pref[L - 1] : 0);
                    ans += 1LL * cur[d] * sum;
                }
            }
        }

        // 將當前子樹的資料合併進總統計 cnt 中
        for (int d = 1; d <= mx_d; ++d) {
            cnt[d] += cur[d];
            cur[d] = 0; // 順手清空 cur 給下一個子樹使用
        }
        
        // 增量重建前綴和陣列
        for (int d = 1; d <= mx_d; ++d) {
            pref[d] = pref[d - 1] + cnt[d];
        }
        
        current_max_depth = mx_d;
    }

    // 還原全域陣列，為下一層重心剖分做準備 (只清空有動到的範圍)
    for (int d = 0; d <= current_max_depth; ++d) {
        cnt[d] = 0;
        pref[d] = 0;
    }

    removed_node[centroid] = true;

    // 遞迴處理剩下的連通分量
    for (int v : adj[centroid]) {
        if (!removed_node[v]) {
            build(v);
        }
    }
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k1 >> k2)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 從節點 1 開始建構
    build(1);

    cout << ans << "\n";

    return 0;
}