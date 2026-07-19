#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    const int INF = 1e9;
    int tmp[2][3005][26];
    for (int a = 0; a < 2; a++)
        for (int b = 0; b < n + 1; b++)
            for (int c = 0; c < k; c++)
                tmp[a][b][c] = INF;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mx = 0;
            for (int c = 0; c < k; c++) {
                int val = (grid[i][j] == 'A' + c) ? 0 : INF;
                int v1 = tmp[(i + 1) & 1][j][c];
                int v2 = tmp[i & 1][j + 1][c];
                int v3 = tmp[(i + 1) & 1][j + 1][c];
                int mn = min({v1, v2, v3});
                tmp[i & 1][j][c] = min(val, mn == INF ? INF : mn + 1);
                if (tmp[i & 1][j][c] > mx) mx = tmp[i & 1][j][c];
            }
            ans += max(n - max(i, j) - mx, 0);
        }
    }
    cout << ans << "\n";
    return 0;
}
