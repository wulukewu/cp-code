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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int c = grid[i][j] - 'A';
            int maxSz = min(sameRight[i][j], sameDown[i][j]);
            for (int sz = 1; sz <= maxSz; sz++) {
                if (sz == 1) { ans[c]++; continue; }
                int bi = i + sz - 1, bj = j + sz - 1;
                if (sameDown[i][bj] >= sz && sameRight[bi][j] >= sz)
                    ans[c]++;
            }
        }
    for (int i = 0; i < k; i++) cout << ans[i] << "\n";
    return 0;
}
