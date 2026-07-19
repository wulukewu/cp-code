#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
bool removed_node[MAXN]; // 標記作為重心被拔除的節點
int sz[MAXN];
int cnt[MAXN];
int k;
long long ans = 0;       // 答案可能超過 32-bit int，必須用 long long
int max_depth = 0;

// 計算子樹大小
void get_sizes(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed_node[v]) {
            get_sizes(v, u);
            sz[u] += sz[v];
        }
    }
}

// 尋找樹的重心
int get_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p && !removed_node[v] && sz[v] > total / 2) {
            return get_centroid(v, u, total);
        }
    }
    return u;
}

// 處理路徑查詢與更新 cnt 陣列
void get_cnt(int u, int p, int depth, bool is_query) {
    // 超過目標長度就沒有繼續往下找的必要
    if (depth > k) return;
    
    // 記錄遍歷到的最大深度，以便後續用 O(1) 級別的均攤時間清空 cnt
    max_depth = max(max_depth, depth);
    
    if (is_query) {
        ans += cnt[k - depth]; // 找尋另一棵子樹中深度為 k - depth 的節點
    } else {
        cnt[depth]++;          // 將當前節點的深度記錄下來
    }
    
    for (int v : adj[u]) {
        if (v != p && !removed_node[v]) {
            get_cnt(v, u, depth + 1, is_query);
        }
    }
}

// 重心剖分主函式
void build(int u) {
    get_sizes(u, 0);
    int centroid = get_centroid(u, 0, sz[u]);
    
    // cnt[0] 設為 1，代表從重心自己出發的路徑
    cnt[0] = 1;
    max_depth = 0;
    
    for (int v : adj[centroid]) {
        if (!removed_node[v]) {
            // 1. 先查詢：計算與前面已經走過的子樹能組成的合法路徑
            get_cnt(v, centroid, 1, true);
            // 2. 後加入：將當前子樹的節點深度納入 cnt
            get_cnt(v, centroid, 1, false);
        }
    }
    
    // 恢復 cnt 陣列，只清空有修改過的部分以保證 O(N log N) 的時間複雜度
    fill(cnt + 1, cnt + max_depth + 1, 0);
    
    removed_node[centroid] = true;
    
    // 對剩餘的連通分量遞迴進行重心剖分
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

    int n;
    if (!(cin >> n >> k)) return 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 從節點 1 開始進行重心剖分
    build(1);

    cout << ans << "\n";

    return 0;
}