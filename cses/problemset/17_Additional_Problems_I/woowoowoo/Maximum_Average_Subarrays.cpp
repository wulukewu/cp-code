#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  double lo = 0, hi = 1e6;
  for (int it = 0; it < 60; it++) {
    double mid = (lo + hi) / 2;
    vector<double> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i] - mid;
    double mn = 0;
    bool ok = false;
    for (int i = k; i <= n; i++) {
      mn = min(mn, pref[i - k]);
      if (pref[i] >= mn) { ok = true; break; }
    }
    if (ok) lo = mid;
    else hi = mid;
  }
  cout << fixed << setprecision(9) << lo << "\n";
  return 0;
}
