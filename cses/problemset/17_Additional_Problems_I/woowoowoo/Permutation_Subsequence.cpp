#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i < n; i++) {
    pos[p[i]].push_back(i);
  }
  int ans = 0;
  vector<int> ptr(n + 1, 0);
  while (true) {
    int cur = -1;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      while (ptr[i] < (int)pos[i].size() && pos[i][ptr[i]] <= cur) ptr[i]++;
      if (ptr[i] == (int)pos[i].size()) { ok = false; break; }
      cur = pos[i][ptr[i]];
    }
    if (!ok) break;
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
