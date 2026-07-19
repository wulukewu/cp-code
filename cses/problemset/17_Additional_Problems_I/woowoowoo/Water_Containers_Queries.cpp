#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, q;
  cin >> a >> b >> q;
  queue<pair<int,int>> qu;
  set<pair<int,int>> vis;
  map<pair<int,int>, int> dist;
  qu.push({0, 0});
  vis.insert({0, 0});
  dist[{0, 0}] = 0;
  while (!qu.empty()) {
    auto [x, y] = qu.front(); qu.pop();
    int d = dist[{x, y}];
    vector<pair<int,int>> nxt = {
      {a, y}, {x, b}, {0, y}, {x, 0},
      {max(0, x - (b - y)), min(b, y + x)},
      {min(a, x + y), max(0, y - (a - x))}
    };
    for (auto [nx, ny] : nxt) {
      if (!vis.count({nx, ny})) {
        vis.insert({nx, ny});
        dist[{nx, ny}] = d + 1;
        qu.push({nx, ny});
      }
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    auto it = dist.find({x, y});
    cout << (it == dist.end() ? -1 : it->second) << "\n";
  }
  return 0;
}
