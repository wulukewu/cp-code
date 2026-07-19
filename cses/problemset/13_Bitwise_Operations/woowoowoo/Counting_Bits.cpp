#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; (1LL << i) <= n; i++) {
        long long cycle = 1LL << (i + 1);
        long long full = n / cycle;
        long long rem = n % cycle;
        ans += full * (1LL << i) + max(0LL, rem - (1LL << i) + 1);
    }

    cout << ans << "\n";
    return 0;
}
