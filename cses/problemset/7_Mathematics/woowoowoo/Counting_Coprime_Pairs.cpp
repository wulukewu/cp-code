#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> freq(MAX + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    vector<int> mu(MAX + 1, 1);
    vector<bool> comp(MAX + 1, false);
    vector<int> primes;
    for (int i = 2; i <= MAX; i++) {
        if (!comp[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > MAX) break;
            comp[i * p] = true;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }
            mu[i * p] = -mu[i];
        }
    }
    ll ans = 0;
    for (int d = 1; d <= MAX; d++) {
        if (mu[d] == 0) continue;
        ll cnt = 0;
        for (int m = d; m <= MAX; m += d)
            cnt += freq[m];
        ans += mu[d] * cnt * (cnt - 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
