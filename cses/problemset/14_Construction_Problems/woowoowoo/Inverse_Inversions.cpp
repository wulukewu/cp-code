#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	int hi = n, lo = 1;
	int perm[n + 1];
	for (int i = 1; i <= n; i++) {
		if (k >= n - i) {
			perm[i] = lo++;
			k -= n - i;
		} else {
			perm[i] = hi--;
		}
	}
	for (int i = n; i > 0; i--) cout << perm[i] << " ";
	cout << "\n";
	return 0;
}
