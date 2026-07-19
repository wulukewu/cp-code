#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> dp(n + 1, vector<long long>(n * 50 + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int c = i; c >= 0; c--) {
      for (int s = 0; s <= c * 50; s++) {
        if (dp[c][s]) dp[c + 1][s + a[i]] += dp[c][s];
      }
    }
  }
  long long ans = 0;
  for (int c = 1; c <= n; c++) {
    if (c * x <= n * 50) ans += dp[c][c * x];
  }
  cout << ans << "\n";
  return 0;
}
