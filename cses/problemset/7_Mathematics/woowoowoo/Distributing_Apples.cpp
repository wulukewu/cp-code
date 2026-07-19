#include <iostream>
using namespace std;

const long long MOD = 1000000007;
const int MAX = 2000000;
long long fac[MAX + 1];
long long inv[MAX + 1];

long long modpow(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAX] = modpow(fac[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    int n, m;
    cin >> n >> m;
    long long ans = fac[n + m - 1] * inv[n - 1] % MOD * inv[m] % MOD;
    cout << ans << '\n';
    return 0;
}
