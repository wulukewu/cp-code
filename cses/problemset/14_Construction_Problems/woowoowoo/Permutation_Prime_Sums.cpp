#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000000;
vector<char> is_prime(N + 1, true);
vector<int> primes;

void seive() {
	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 3; i * i <= N; i += 2) {
		if (is_prime[i]) {
			for (int j = i * i; j <= N; j += i)
				is_prime[j] = false;
		}
	}
	primes.push_back(2);
	for (int i = 3; i < N; i += 2) {
		if (is_prime[i]) primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	seive();
	int n;
	cin >> n;
	vector<int> ara(n + 1, 0);
	int cur = n;
	while (cur > 0) {
		int prime = *upper_bound(primes.begin(), primes.end(), cur);
		int a = prime / 2;
		int b = prime - a;
		while (a > 0 && b <= cur) {
			ara[a] = b;
			ara[b] = a;
			a--;
			b++;
		}
		cur = a;
	}
	for (int i = 1; i <= n; i++) cout << i << " ";
	cout << "\n";
	for (int i = 1; i <= n; i++) cout << ara[i] << " ";
	cout << "\n";
	return 0;
}
