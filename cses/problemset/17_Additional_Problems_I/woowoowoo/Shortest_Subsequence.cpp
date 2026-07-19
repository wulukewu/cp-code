#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int ca = 0, cc = 0, cg = 0, ct = 0;
  for (char c : s) {
    if (c == 'A') ca = 1;
    else if (c == 'C') cc = 1;
    else if (c == 'G') cg = 1;
    else ct = 1;
    if (ca && cc && cg && ct) {
      cout << 'A';
      ca = cc = cg = ct = 0;
    }
  }
  if (!ca) cout << 'A';
  else if (!cc) cout << 'C';
  else if (!cg) cout << 'G';
  else cout << 'T';
  return 0;
}
