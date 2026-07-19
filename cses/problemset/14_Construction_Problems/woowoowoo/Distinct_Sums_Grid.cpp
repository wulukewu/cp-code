#include <iostream>
#include <algorithm>
using namespace std;

int n, a[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if (n <= 3) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	if (n == 4) {
		cout << "1 1 3 2\n2 1 2 4\n3 3 3 4\n2 1 4 4\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) a[1][i] = n - i + 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < n; j++) a[i][j] = i;
		a[i][n] = 1;
	}
	if (n & 1) {
		swap(a[n / 2 + 2][n / 2 + 1], a[n / 2 + 2][n]);
	} else {
		swap(a[n / 2][1], a[n / 2 + 1][1]);
		swap(a[n / 2 + 2][1], a[n / 2 + 3][1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
