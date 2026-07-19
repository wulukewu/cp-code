#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  vector<long long> dp(n + 1, 0);
  vector<int> last(2, -1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = (dp[i - 1] * 2) % MOD;
    if (last[s[i - 1] - '0'] != -1) {
      dp[i] = (dp[i] - dp[last[s[i - 1] - '0'] - 1] + MOD) % MOD;
    }
    last[s[i - 1] - '0'] = i;
  }
  cout << dp[n] << "\n";
  return 0;
}
