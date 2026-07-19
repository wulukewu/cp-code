#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 定義上下左右四個方向
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m;

// 使用非遞迴的 BFS 將當前房間的所有地板標記為牆壁
void bfs(int start_x, int start_y, vector<string>& grid) {
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    grid[start_x][start_y] = '#'; // 直接修改地圖標記為已訪問

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 邊界檢查與是否為地板檢查
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
                grid[nx][ny] = '#'; // 標記為已訪問
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int room_count = 0;

    // 掃描整個地圖
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                room_count++;
                bfs(i, j, grid); // 把這間房間連通的所有點都填滿
            }
        }
    }

    cout << room_count << "\n";

    return 0;
}