#include <iostream>
using namespace std;

const long long MOD = 1000000007;

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

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + modpow(m, gcd(i, (int)n))) % MOD;
    ans = ans * modpow(n, MOD - 2) % MOD;
    cout << ans << '\n';
    return 0;
}
