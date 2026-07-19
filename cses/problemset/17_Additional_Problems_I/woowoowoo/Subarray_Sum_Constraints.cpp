#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<vector<pair<int,ll>>> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u - 1].push_back({v, w});
    g[v].push_back({u - 1, -w});
  }
  vector<ll> p(n + 1);
  vector<bool> vis(n + 1);
  bool bad = false;
  function<void(int,ll)> dfs = [&](int node, ll cur) {
    if (vis[node]) {
      if (cur != p[node]) bad = true;
      return;
    }
    vis[node] = true;
    p[node] = cur;
    for (auto &e : g[node]) dfs(e.first, cur + e.second);
  };
  for (int i = 0; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  if (bad) { cout << "NO\n"; return 0; }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << p[i + 1] - p[i] << " \n"[i + 1 == n];
}
