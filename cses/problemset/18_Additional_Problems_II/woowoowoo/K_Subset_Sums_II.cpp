#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<long long> dp(k + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int s = k; s >= a[i]; s--) {
      dp[s] += dp[s - a[i]];
    }
  }
  long long ans = 0;
  for (int s = 1; s <= k; s++) ans += dp[s];
  cout << ans << "\n";
  return 0;
}
