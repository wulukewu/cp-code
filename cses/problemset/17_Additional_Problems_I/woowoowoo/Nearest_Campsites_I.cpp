#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  queue<pair<int,int>> q;
  vector<vector<int>> d(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'X') {
        d[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m && d[nr][nc] == -1) {
        d[nr][nc] = d[r][c] + 1;
        q.push({nr, nc});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << d[i][j] << " \n"[j + 1 == m];
    }
  }
  return 0;
}
