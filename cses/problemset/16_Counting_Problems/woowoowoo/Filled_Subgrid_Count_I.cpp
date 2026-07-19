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
    vector<long long> res(k, 0);
    for (int l = 0; l < k; l++) {
        vector<vector<int>> dp_up(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp_left(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp_sq(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (grid[i-1][j-1] != 'A' + l) continue;
                dp_up[i][j] = dp_up[i-1][j] + 1;
                dp_left[i][j] = dp_left[i][j-1] + 1;
                dp_sq[i][j] = min({dp_up[i-1][j], dp_left[i][j-1], dp_sq[i-1][j-1]}) + 1;
                res[l] += dp_sq[i][j];
            }
    }
    for (int i = 0; i < k; i++) cout << res[i] << "\n";
    return 0;
}
