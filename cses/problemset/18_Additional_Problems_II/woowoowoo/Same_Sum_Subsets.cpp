#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  int total = 0;
  for (int i = 0; i < n; i++) { cin >> a[i]; total += a[i]; }
  if (total % 2) { cout << "0\n"; return 0; }
  int half = total / 2;
  vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int s = 0; s <= half; s++) {
      if (dp[i][s]) {
        dp[i + 1][s] = true;
        if (s + a[i] <= half) dp[i + 1][s + a[i]] = true;
      }
    }
  }
  if (!dp[n][half]) { cout << "0\n"; return 0; }
  cout << "1\n";
  vector<int> ans;
  int s = half;
  for (int i = n; i >= 1; i--) {
    if (s >= a[i - 1] && dp[i - 1][s - a[i - 1]]) {
      ans.push_back(i);
      s -= a[i - 1];
    }
  }
  cout << ans.size() << "\n";
  for (int i = (int)ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " \n"[i == 0];
  }
  return 0;
}
