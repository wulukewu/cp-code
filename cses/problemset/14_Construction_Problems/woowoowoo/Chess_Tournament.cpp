#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a) s.insert({a, i});
	}
	vector<pair<int, int>> res;
	while (s.size() >= 2) {
		auto [u, itu] = *s.begin();
		s.erase({u, itu});
		vector<pair<int, int>> store;
		while (u && s.size()) {
			auto [v, itv] = *s.rbegin();
			s.erase({v, itv});
			u--;
			v--;
			res.push_back({itu, itv});
			store.push_back({v, itv});
		}
		if (u) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		for (auto [v, itv] : store) {
			if (v) s.insert({v, itv});
		}
	}
	if (s.size()) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << res.size() << "\n";
	for (auto [u, v] : res) cout << u << " " << v << "\n";
	return 0;
}
