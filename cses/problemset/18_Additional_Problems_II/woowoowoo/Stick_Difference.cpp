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
  long long ans = 1e18;
  for (int i = 1; i < n; i++) ans = min(ans, a[i] - a[i - 1]);
  cout << ans << "\n";
  return 0;
}
