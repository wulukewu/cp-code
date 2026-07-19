#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> p(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }

    long long ans = total;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) sum += p[i];
        }
        ans = min(ans, llabs(total - 2 * sum));
    }

    cout << ans << "\n";

    return 0;
}
