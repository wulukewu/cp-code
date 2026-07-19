#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXV = 1000000;

long long modpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(MAXV + 1, 0);
  for (int i = 0; i < n; i++) { cin >> a[i]; cnt[a[i]]++; }
  vector<long long> dp(MAXV + 1, 0);
  for (int i = MAXV; i >= 1; i--) {
    int total = 0;
    for (int j = i; j <= MAXV; j += i) total += cnt[j];
    if (total > 0) {
      dp[i] = (modpow(2, total) - 1 + MOD) % MOD;
      for (int j = 2 * i; j <= MAXV; j += i) {
        dp[i] = (dp[i] - dp[j] + MOD) % MOD;
      }
    }
  }
  cout << dp[1] << "\n";
  return 0;
}
