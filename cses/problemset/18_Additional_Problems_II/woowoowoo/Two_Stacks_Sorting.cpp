#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  stack<int> s1, s2;
  int need = 1;
  vector<char> ans;
  for (int x : a) {
    while (!s1.empty() && s1.top() == need) {
      ans.push_back('B');
      s1.pop();
      need++;
    }
    if (s1.empty() || x < s1.top()) {
      s1.push(x);
      ans.push_back('A');
    } else if (s2.empty() || (!s2.empty() && x < s2.top())) {
      s2.push(x);
      ans.push_back('C');
    } else {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    while (!s1.empty() && s1.top() == need) {
      ans.push_back('B');
      s1.pop();
      need++;
    }
    while (!s2.empty() && s2.top() == need) {
      ans.push_back('D');
      s2.pop();
      need++;
    }
  }
  while (!s1.empty() && s1.top() == need) {
    ans.push_back('B');
    s1.pop();
    need++;
  }
  while (!s2.empty() && s2.top() == need) {
    ans.push_back('D');
    s2.pop();
    need++;
  }
  if (need != n + 1) { cout << "IMPOSSIBLE\n"; return 0; }
  for (char c : ans) cout << c << " ";
  cout << "\n";
  return 0;
}
