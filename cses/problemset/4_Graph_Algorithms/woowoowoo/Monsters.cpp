#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 定義方向
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir_chars[4] = {'U', 'D', 'L', 'R'};

const int INF = 1e9;

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    queue<pair<int, int>> monster_q;
    vector<vector<int>> monster_dist(n, vector<int>(m, INF));

    int start_x = -1, start_y = -1;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                monster_q.push({i, j});
                monster_dist[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    // 1. 多源 BFS：計算所有怪物到達每格的最短距離
    while (!monster_q.empty()) {
        auto [x, y] = monster_q.front();
        monster_q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && monster_dist[nx][ny] == INF) {
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                monster_q.push({nx, ny});
            }
        }
    }

    // 2. 單源 BFS：計算人逃跑的路徑
    queue<pair<int, int>> human_q;
    vector<vector<int>> human_dist(n, vector<int>(m, INF));
    vector<vector<int>> p(n, vector<int>(m, -1)); // 記錄上一步的方向索引

    human_q.push({start_x, start_y});
    human_dist[start_x][start_y] = 0;

    int exit_x = -1, exit_y = -1;

    while (!human_q.empty()) {
        auto [x, y] = human_q.front();
        human_q.pop();

        // 只要走到邊界，就代表成功逃脫
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            exit_x = x;
            exit_y = y;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                int next_dist = human_dist[x][y] + 1;
                // 人必須比怪物「更早」到達該格子，且該格尚未被訪問過
                if (next_dist < monster_dist[nx][ny] && human_dist[nx][ny] == INF) {
                    human_dist[nx][ny] = next_dist;
                    p[nx][ny] = i; // 記錄是由方向 i 走過來的
                    human_q.push({nx, ny});
                }
            }
        }
    }

    // 3. 輸出結果與路徑回溯
    if (exit_x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        string path = "";
        int cur_x = exit_x, cur_y = exit_y;

        while (cur_x != start_x || cur_y != start_y) {
            int dir_idx = p[cur_x][cur_y];
            path.push_back(dir_chars[dir_idx]);
            
            // 沿著移動的反方向倒推回上一格
            cur_x -= dx[dir_idx];
            cur_y -= dy[dir_idx];
        }

        reverse(path.begin(), path.end());
        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}