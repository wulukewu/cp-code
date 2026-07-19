#include <iostream>
#include <string>
using namespace std;

const long long MOD = 1000000007;
const int MAX = 1000000;
long long fact[MAX + 1];
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
    int n;
    string s;
    cin >> n >> s;
    if (n % 2) {
        cout << 0 << '\n';
        return 0;
    }
    n /= 2;
    int k = s.size();
    int c = 0, x = 0, y = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '(') c++, x++;
        else c--, y++;
        if (c < 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    if (x > n) {
        cout << 0 << '\n';
        return 0;
    }
    if (x == n) {
        cout << 1 << '\n';
        return 0;
    }
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv[MAX] = modpow(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    long long ans = fact[2 * n - x - y] * inv[n - x] % MOD * inv[n - y] % MOD;
    ans = (ans - fact[2 * n - x - y] * inv[n - x - 1] % MOD * inv[n - y + 1] % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}
