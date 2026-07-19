#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  long long sa = 0, sb = 0;
  for (int i = 0; i < n; i++) { cin >> a[i]; sa += a[i]; }
  for (int i = 0; i < m; i++) { cin >> b[i]; sb += b[i]; }
  if (sa * m != sb * n) { cout << "-1\n"; return 0; }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ans = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] < b[j]) {
      ans += b[j] - a[i];
      i++;
    } else if (a[i] > b[j]) {
      ans += a[i] - b[j];
      j++;
    } else {
      i++; j++;
    }
  }
  cout << ans << "\n";
  return 0;
}
