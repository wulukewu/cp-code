#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 騎士 (Knight) 的 8 種移動方向
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int grid[8][8] = {0}; // 棋盤，記錄步數

// 檢查該座標是否合法且尚未走過
bool isValid(int r, int c) {
    return (r >= 0 && r < 8 && c >= 0 && c < 8 && grid[r][c] == 0);
}

// 計算某個格子的「出口數」(Degree)
int getDegree(int r, int c) {
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (isValid(nr, nc)) {
            count++;
        }
    }
    return count;
}

// 深度優先搜索 (DFS) 搭配 Warnsdorff's Rule
bool solve(int r, int c, int step) {
    // 記錄當前步數
    grid[r][c] = step;
    
    // 成功走滿 64 步，結束搜索
    if (step == 64) return true;

    // 收集所有合法的下一步
    vector<pair<int, int>> next_moves;
    for (int i = 0; i < 8; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (isValid(nr, nc)) {
            // 儲存格式：{該鄰居的出口數, 方向索引}
            next_moves.push_back({getDegree(nr, nc), i});
        }
    }

    // Warnsdorff's Rule：依照出口數由小到大排序
    // 出口越少的格子，代表它越容易變成死胡同，所以要優先去走
    sort(next_moves.begin(), next_moves.end());

    // 依照排序後的順序進行 DFS
    for (auto move : next_moves) {
        int dir = move.second;
        int nr = r + dx[dir];
        int nc = c + dy[dir];
        if (solve(nr, nc, step + 1)) {
            return true;
        }
    }

    // 如果所有方向都走不通，進行回溯 (Backtracking)
    grid[r][c] = 0;
    return false;
}

int main() {
    // 快速 I/O 優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    if (cin >> x >> y) {
        // x 是行 (Column), y 是列 (Row)
        // 轉換為 0-based index
        int start_row = y - 1;
        int start_col = x - 1;

        solve(start_row, start_col, 1);

        // 輸出解答
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << grid[i][j] << (j == 7 ? "" : " ");
            }
            cout << "\n";
        }
    }
    
    return 0;
}