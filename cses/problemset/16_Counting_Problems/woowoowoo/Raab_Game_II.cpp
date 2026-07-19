#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 5005;
long long f[MAXN][MAXN];
long long fact[MAXN], inv[MAXN];

long long modpow(long long x, long long y) {
    long long ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

long long C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = modpow(fact[i], MOD - 2);
    }
    f[0][0] = 1;
    for (int s = 1; s < MAXN; s++) {
        for (int a = 0; a <= s; a++) {
            int b = s - a;
            if (a > 0) f[a][b] = (f[a][b] + f[a-1][b] * b) % MOD;
            if (b > 0) f[a][b] = (f[a][b] + f[a][b-1] * a) % MOD;
            if (a > 0 && b > 0) f[a][b] = (f[a][b] + f[a-1][b-1] * (s - 1)) % MOD;
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        if (a + b > n || (min(a, b) == 0 && max(a, b) != 0)) {
            cout << 0 << "\n";
            continue;
        }
        long long ans = C(n, a + b) * f[a][b] % MOD * fact[n] % MOD;
        cout << ans << "\n";
    }
    return 0;
}
