#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 騎士 (Knight) 的 8 種移動方向
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    // 快速 I/O 優化，因為要輸出 n*n 個數字，I/O 速度非常關鍵
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 初始化距離陣列為 -1，代表尚未走到
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // 從左上角起點出發
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 檢查是否超出邊界，以及是否已經走訪過
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 輸出整個棋盤的步數
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}