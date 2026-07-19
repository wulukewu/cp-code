#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
  } else if (n == 2) {
    cout << "1 2\n";
  } else if (n == 3) {
    cout << "2 3 1\n";
  } else {
    vector<int> ans;
    int l = 1, r = n;
    while (l <= r) {
      if (l == r) { ans.push_back(l); break; }
      ans.push_back(l++);
      if (l <= r) ans.push_back(r--);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << (i + 1 == n ? "\n" : " ");
    }
  }
  return 0;
}
