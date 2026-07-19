#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  while (n > 1) {
    long long g = 0;
    for (int i = 0; i < n; i++) g = gcd(g, a[i]);
    if (g > 0) break;
    vector<long long> b;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] != a[i + 1]) b.push_back(abs(a[i] - a[i + 1]));
    }
    if (b.empty()) { a = {0}; n = 1; break; }
    a = b;
    n = a.size();
  }
  for (int i = 0; i < n; i++) cout << a[i] << " \n"[i + 1 == n];
  return 0;
}
