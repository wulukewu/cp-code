#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  int ans = 0;
  while (n > 0) {
    long long tmp = n;
    int mx = 0;
    while (tmp) { mx = max(mx, (int)(tmp % 10)); tmp /= 10; }
    n -= mx;
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
