#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int u, v;
    long long weight;
};

int n, m;
vector<Edge> edges;
vector<vector<int>> adj, radj;
vector<bool> from_1, to_n;

// DFS 標記從起點 1 可達的所有節點
void dfs1(int u) {
    from_1[u] = true;
    for (int v : adj[u]) {
        if (!from_1[v]) dfs1(v);
    }
}

// DFS 在反向圖上標記能到達終點 n 的所有節點
void dfs2(int u) {
    to_n[u] = true;
    for (int v : radj[u]) {
        if (!to_n[v]) dfs2(v);
    }
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    radj.resize(n + 1);
    from_1.assign(n + 1, false);
    to_n.assign(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // 取負號：將最大化問題轉為最小化問題
        edges.push_back({u, v, -w});
        adj[u].push_back(v);
        radj[v].push_back(u); // 反向邊用於可達性分析
    }

    // 1. 篩選出有效節點（必須在 1 到 n 的路徑上）
    dfs1(1);
    dfs2(n);

    // 2. 執行 Bellman-Ford 演算法
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    // 迭代 n - 1 次求最短路
    for (int i = 1; i < n; ++i) {
        for (const auto& e : edges) {
            if (!from_1[e.u] || !to_n[e.v]) continue; // 剪枝：跳過無效邊
            if (dist[e.u] < INF && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }

    // 第 n 次迭代：若還能更新，代表 1 到 n 的路徑上存在可以刷分數的環
    bool has_cycle = false;
    for (const auto& e : edges) {
        if (!from_1[e.u] || !to_n[e.v]) continue;
        if (dist[e.u] < INF && dist[e.u] + e.weight < dist[e.v]) {
            has_cycle = true;
            break;
        }
    }

    if (has_cycle) {
        cout << "-1\n";
    } else {
        // 將結果再次取負號，還原為最大得分
        cout << -dist[n] << "\n";
    }

    return 0;
}