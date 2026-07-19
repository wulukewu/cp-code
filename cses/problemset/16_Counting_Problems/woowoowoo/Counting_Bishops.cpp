#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
ll fac[505], inv[505];
ll T[505], B[1005], W[1005];

ll modpow(ll x, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * x % MOD;
        x = x * x % MOD;
        b >>= 1;
    }
    return res;
}

ll choose(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

ll stirling2(int n, int k) {
    ll sum = 0;
    for (int i = 0; i <= k; i++) {
        ll term = (i & 1 ? MOD - 1 : 1) * choose(k, i) % MOD * modpow(k - i, n) % MOD;
        sum = (sum + term) % MOD;
    }
    return sum * inv[k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fac[0] = inv[0] = 1;
    for (int i = 1; i < 505; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = modpow(fac[i], MOD - 2);
    }
    int n, k; cin >> n >> k;
    if (k >= 2 * n) { cout << 0 << "\n"; return 0; }
    if (k == 0) { cout << 1 << "\n"; return 0; }
    memset(T, 0, sizeof T);
    memset(B, 0, sizeof B);
    memset(W, 0, sizeof W);
    int m = n / 2, odd = n & 1;
    for (int x = 0; x <= m + odd; x++) {
        for (int i = 0; i <= 2 * m - 1 - x + odd; i++)
            T[i] = stirling2(2 * m - x, 2 * m - x - i);
        ll a = choose(m + odd, x);
        ll b = choose(m, x);
        for (int i = 0; i + x < n; i++) {
            B[i + x] = (B[i + x] + a * T[i]) % MOD;
            W[i + x] = (W[i + x] + b * T[i]) % MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= min(k, n - 1); i++) {
        if (k - i < n) ans = (ans + B[i] * W[k - i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
