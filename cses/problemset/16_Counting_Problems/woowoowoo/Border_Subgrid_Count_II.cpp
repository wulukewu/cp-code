#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<int>> sameDown(n, vector<int>(n, 1));
    vector<vector<int>> sameRight(n, vector<int>(n, 1));
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--) {
            if (i + 1 < n && grid[i][j] == grid[i+1][j]) sameDown[i][j] = sameDown[i+1][j] + 1;
            if (j + 1 < n && grid[i][j] == grid[i][j+1]) sameRight[i][j] = sameRight[i][j+1] + 1;
        }
    vector<long long> ans(k, 0);
    // 1x1 subgrids
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[grid[i][j] - 'A']++;
    // 1xW and Hx1 subgrids (H,W >= 2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = grid[i][j] - 'A';
            int W = sameRight[i][j];
            if (W >= 2) ans[c] += W - 1;
            int H = sameDown[i][j];
            if (H >= 2) ans[c] += H - 1;
        }
    }
    // HxW subgrids with H,W >= 2
    for (int top = 0; top < n; top++) {
        for (int bot = top + 1; bot < n; bot++) {
            int h = bot - top + 1;
            for (int left = 0; left < n; left++) {
                if (sameDown[top][left] < h) continue;
                int c = grid[top][left] - 'A';
                int maxW = min(sameRight[top][left], sameRight[bot][left]);
                if (maxW < 2) continue;
                for (int right = left + 1; right <= left + maxW - 1 && right < n; right++) {
                    if (sameDown[top][right] >= h) ans[c]++;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) cout << ans[i] << "\n";
    return 0;
}
