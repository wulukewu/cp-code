#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  queue<pair<int,int>> q;
  set<pair<int,int>> vis;
  q.push({0, 0});
  vis.insert({0, 0});
  int steps = 0;
  while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
      auto [x, y] = q.front(); q.pop();
      if (x == c || y == c) { cout << steps << "\n"; return 0; }
      vector<pair<int,int>> nxt = {
        {a, y}, {x, b}, {0, y}, {x, 0},
        {max(0, x - (b - y)), min(b, y + x)},
        {min(a, x + y), max(0, y - (a - x))}
      };
      for (auto [nx, ny] : nxt) {
        if (!vis.count({nx, ny})) {
          vis.insert({nx, ny});
          q.push({nx, ny});
        }
      }
    }
    steps++;
  }
  cout << "-1\n";
  return 0;
}
