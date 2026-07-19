#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		int slots = (n + x - 1) / x;
		if (slots > x) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 1; i <= slots; i++) {
			int st = min(n, i * x);
			int en = (i - 1) * x + 1;
			for (int j = st; j >= en; j--) cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}
