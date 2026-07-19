#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) cin >> g[i];
  vector<vector<int>> ans(n, vector<int>(m, 0));
  int color = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '#' && ans[i][j] == 0) {
        queue<pair<int,int>> q;
        q.push({i, j});
        ans[i][j] = color;
        while (!q.empty()) {
          auto [r, c] = q.front(); q.pop();
          int dr[] = {-1, 0, 1, 0};
          int dc[] = {0, 1, 0, -1};
          for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == '#' && ans[nr][nc] == 0) {
              ans[nr][nc] = color;
              q.push({nr, nc});
            }
          }
        }
        color++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " \n"[j + 1 == m];
    }
  }
  return 0;
}
