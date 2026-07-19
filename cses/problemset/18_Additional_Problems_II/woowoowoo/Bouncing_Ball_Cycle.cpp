#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--; y--;
  string s;
  cin >> s;
  map<pair<int,int>, int> first;
  first[{x, y}] = 0;
  int step = 0;
  long long cycle_len = -1;
  while (true) {
    int nx = x, ny = y;
    char c = s[step % s.size()];
    step++;
    if (c == 'L') ny--;
    else if (c == 'R') ny++;
    else if (c == 'U') nx--;
    else nx++;
    if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
      x = nx; y = ny;
    }
    auto key = make_pair(x, y);
    if (first.count(key)) {
      long long cycle_start = first[key];
      cycle_len = step - cycle_start;
      break;
    }
    first[key] = step;
  }
  cout << cycle_len << "\n";
  return 0;
}
