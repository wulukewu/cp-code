#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<long long> dp(n + 1, 1e18);
  dp[0] = 0;
  for (int i = 2; i <= n; i++) {
    if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + (a[i - 1] - a[i - 2]) * (a[i - 1] - a[i - 2]));
    if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + (a[i - 1] - a[i - 3]) * (a[i - 1] - a[i - 3]));
  }
  cout << dp[n] << "\n";
  return 0;
}
