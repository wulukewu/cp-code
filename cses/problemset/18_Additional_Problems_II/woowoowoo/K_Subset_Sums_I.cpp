#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<bool> dp(k + 1, false);
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    for (int s = k; s >= a[i]; s--) {
      if (dp[s - a[i]]) dp[s] = true;
    }
  }
  vector<int> ans;
  for (int s = 1; s <= k; s++) if (dp[s]) ans.push_back(s);
  cout << ans.size() << "\n";
  for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
  return 0;
}
