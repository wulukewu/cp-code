#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 使用極大的值代表無窮大

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // 初始化鄰接矩陣
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    // 讀取邊，並處理多重邊的情況（只保留最短的邊）
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) {
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }

    // Floyd-Warshall 核心三層迴圈
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // O(1) 回答每筆詢問
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (dist[u][v] >= INF) {
            cout << "-1\n";
        } else {
            cout << dist[u][v] << "\n";
        }
    }

    return 0;
}