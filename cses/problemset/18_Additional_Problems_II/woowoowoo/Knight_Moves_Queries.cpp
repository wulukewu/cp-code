#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    if (a == c && b == d) { cout << "0\n"; continue; }
    vector<vector<int>> dist(8, vector<int>(8, INF));
    queue<pair<int,int>> qu;
    dist[a][b] = 0;
    qu.push({a, b});
    while (!qu.empty()) {
      auto [r, c2] = qu.front(); qu.pop();
      int d2 = dist[r][c2];
      if (r == c && c2 == d) { cout << d2 << "\n"; break; }
      for (int k = 0; k < 8; k++) {
        int nr = r + dr[k], nc = c2 + dc[k];
        if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && dist[nr][nc] > d2 + 1) {
          dist[nr][nc] = d2 + 1;
          qu.push({nr, nc});
        }
      }
    }
  }
  return 0;
}
