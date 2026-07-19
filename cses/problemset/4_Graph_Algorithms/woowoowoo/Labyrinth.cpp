#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 定義方向：方向字元、x 軸位移、y 軸位移
const char dir_chars[4] = {'U', 'D', 'L', 'R'};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    int start_x = -1, start_y = -1;
    int end_x = -1, end_y = -1;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            } else if (grid[i][j] == 'B') {
                end_x = i;
                end_y = j;
            }
        }
    }

    // p[x][y] 用來記錄走到 (x, y) 的前一步移動方向
    vector<vector<char>> p(n, vector<char>(m, 0));
    queue<pair<int, int>> q;

    // 從起點出發
    q.push({start_x, start_y});
    grid[start_x][start_y] = '#'; // 標記為已訪問

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end_x && y == end_y) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                p[nx][ny] = dir_chars[i];  // 記錄走過來的方向
                grid[nx][ny] = '#';        // 標記為已訪問
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        // 從終點逆向回溯路徑
        string path = "";
        int cur_x = end_x, cur_y = end_y;
        
        while (cur_x != start_x || cur_y != start_y) {
            char move = p[cur_x][cur_y];
            path.push_back(move);
            
            // 根據記錄的方向，反向推回上一個座標
            if (move == 'U') cur_x++;
            else if (move == 'D') cur_x--;
            else if (move == 'L') cur_y++;
            else if (move == 'R') cur_y--;
        }
        
        // 反轉字串得到從 A 到 B 的正確順序
        reverse(path.begin(), path.end());
        
        cout << path.length() << "\n";
        cout << path << "\n";
    }

    return 0;
}