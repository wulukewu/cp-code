#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int N = 1000006;
ll fact[N], inv[N];

ll modpow(ll x, int p) {
    if (p == 0) return 1;
    ll mul = modpow(x, p / 2);
    if (p % 2 == 0) return mul * mul % MOD;
    return mul * mul % MOD * x % MOD;
}

ll C(int n, int r) {
    if (n < r) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i-1] * i % MOD;
    inv[N-1] = modpow(fact[N-1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i+1] * (i+1) % MOD;
    int n, m; cin >> n >> m;
    ll res = 0;
    for (int i = 0; i < m; i++) {
        ll term = C(m, i) * modpow(m - i, n) % MOD;
        if (i % 2 == 0) res = (res + term) % MOD;
        else res = (res - term + MOD) % MOD;
    }
    cout << res << "\n";
    return 0;
}
