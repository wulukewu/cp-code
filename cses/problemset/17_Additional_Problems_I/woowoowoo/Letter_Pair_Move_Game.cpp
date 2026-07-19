#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  map<string,int> dist;
  queue<string> q;
  dist[s] = 0;
  q.push(s);
  string goal = s;
  sort(goal.begin(), goal.end());
  while (!q.empty()) {
    string cur = q.front(); q.pop();
    int d = dist[cur];
    if (cur == goal) { cout << d << "\n"; return 0; }
    for (int i = 0; i + 1 < n; i++) {
      swap(cur[i], cur[i+1]);
      if (!dist.count(cur)) {
        dist[cur] = d + 1;
        q.push(cur);
      }
      swap(cur[i], cur[i+1]);
    }
  }
  cout << "-1\n";
  return 0;
}
