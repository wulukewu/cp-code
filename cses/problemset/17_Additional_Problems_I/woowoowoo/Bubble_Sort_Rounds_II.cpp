#include <bits/stdc++.h>
using namespace std;

struct BIT {
  int n;
  vector<int> bit;
  BIT(int n) : n(n), bit(n + 2, 0) {}
  void add(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) bit[idx] += val;
  }
  int sum(int idx) {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx) s += bit[idx];
    return s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> pos(n + 1);
  for (int i = 0; i < n; i++) pos[a[i]] = i;
  BIT bit(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int idx = a[i];
    int greater = bit.sum(n) - bit.sum(idx);
    ans = max(ans, greater);
    bit.add(idx, 1);
  }
  cout << ans;
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    int val = a[l];
    for (int j = l; j < r; j++) a[j] = a[j + 1];
    a[r] = val;
    fill(bit.bit.begin(), bit.bit.end(), 0);
    ans = 0;
    for (int i = 0; i < n; i++) {
      int idx = a[i];
      int greater = bit.sum(n) - bit.sum(idx);
      ans = max(ans, greater);
      bit.add(idx, 1);
    }
    cout << " " << ans;
  }
  cout << "\n";
  return 0;
}
