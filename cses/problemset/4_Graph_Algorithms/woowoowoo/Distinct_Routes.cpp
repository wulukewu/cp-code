#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 定義邊的結構
struct Edge {
    int to;     // 目標節點
    int cap;    // 容量
    int flow;   // 當前流量
    int rev;    // 反向邊在目標節點的鄰接串列中的索引
};

int n, m;
vector<vector<Edge>> adj;
vector<int> level;
vector<int> ptr;

// 新加一條有向邊，容量為 1，同時建立容量為 0 的反向邊供退流使用
void add_edge(int from, int to) {
    adj[from].push_back({to, 1, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

// Dinic's BFS：建立分層圖，判斷是否還能走到終點
bool bfs() {
    fill(level.begin(), level.end(), -1);
    level[1] = 0;
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[n] != -1;
}

// Dinic's DFS：在分層圖上尋找增廣路徑並推播流量
int dfs(int v, int pushed) {
    if (pushed == 0) return 0;
    if (v == n) return pushed;
    
    // 使用 ptr 陣列進行當前弧優化 (Current arc optimization)
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        
        // 只能往下一層推流量，且必須有剩餘容量
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        
        int push = dfs(tr, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;
        
        // 更新正向與反向邊的流量
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(1, 1e9)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    adj.resize(n + 1);
    level.resize(n + 1);
    ptr.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    // 計算最大天數 (最大流)
    int max_days = dinic();
    cout << max_days << "\n";

    // 找出這 max_days 條獨立的路徑
    for (int i = 0; i < max_days; ++i) {
        vector<int> path;
        int curr = 1;
        
        while (curr != n) {
            path.push_back(curr);
            for (auto& edge : adj[curr]) {
                // 如果這是一條原本的正向邊，且我們有推送流量過去
                if (edge.cap == 1 && edge.flow == 1) {
                    edge.flow = 0; // 標記為已使用，避免後續路徑重複走
                    curr = edge.to;
                    break;
                }
            }
        }
        path.push_back(n); // 補上終點

        // 輸出一條完整路徑
        cout << path.size() << "\n";
        for (int j = 0; j < (int)path.size(); ++j) {
            cout << path[j] << (j == (int)path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}