#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int maxN = 505;

ll fact[maxN], inv[maxN];
int p[maxN], q[maxN], C[6];
bool inp[maxN], inq[maxN];

ll modpow(ll x, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * x % MOD;
        x = x * x % MOD;
        b >>= 1;
    }
    return res;
}

ll choose(int x, int y) {
    return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
}

ll f(int i, int j, int k) {
    ll res = choose(C[0], i) * choose(C[1], j) % MOD * choose(C[2], k) % MOD * choose(C[3], i) % MOD;
    res = res * fact[i] % MOD * fact[C[4] - i - j] % MOD * fact[C[5] - i - k] % MOD;
    if ((i + j + k) % 2 == 1) res = (MOD - res) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = modpow(fact[i], MOD - 2);
    }
    memset(C, 0, sizeof C);
    for (int i = 0; i < n; i++) {
        char s[maxN]; cin >> s;
        p[i] = q[i] = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'A') { p[i] = j; inp[j] = true; }
            if (s[j] == 'B') { q[i] = j; inq[j] = true; }
        }
    }
    for (int i = 0; i < n; i++) {
        if (p[i] >= 0 && q[i] >= 0) C[0]++;
        else if (p[i] >= 0) C[1]++;
        else if (q[i] >= 0) C[2]++;
        else C[3]++;
        if (!inp[i]) C[4]++;
        if (!inq[i]) C[5]++;
    }
    ll ans = 0;
    for (int i = 0; i <= C[0]; i++)
        for (int j = 0; j <= C[1]; j++)
            for (int k = 0; k <= C[2]; k++)
                ans = (ans + f(i, j, k)) % MOD;
    cout << ans << "\n";
    return 0;
}
