#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
using ll = long long;
ll gcd(const ll a, const ll b) {
	if (b != 0)
		return gcd(b, a % b);
	return a;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), w(n);
    vector<int> max_weight(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    for (int i = 0; i < n; ++i) {
        a[i]--;
        max_weight[a[i]] = max(max_weight[a[i]], w[i]);
    }
    const int sum_w = accumulate(w.begin(), w.end(), 0);
    const int sum_max = accumulate(max_weight.begin(), max_weight.end(), 0);
    cout << sum_w - sum_max;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	ll t = 1;
	while (t--) {
		solve();
	}
	return 0;
};