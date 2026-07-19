#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int MAXN = 5005;

ll C[MAXN][MAXN];
ll T[MAXN], F[MAXN];
ll f[MAXN];
ll Q[MAXN][MAXN];

ll modpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    ll fact = 1;
    for (int i = 0; i <= n; i++) {
        if (i > 0) fact = fact * i % MOD;
        T[i] = modpow(2, i * (i - 1) / 2);
    }
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = T[i];
        for (int j = 1; j < i; j++)
            F[i] = (F[i] - C[i][j] * F[j] % MOD * T[i - j] % MOD + MOD) % MOD;
    }
    ll invFact = 1;
    for (int i = 1; i <= n; i++) {
        invFact = invFact * modpow(i, MOD - 2) % MOD;
        f[i] = F[i] * invFact % MOD;
    }
    ll curFact = 1;
    for (int i = 1; i <= n; i++) curFact = curFact * i % MOD;
    Q[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        Q[i][1] = f[i];
    }
    for (int k = 2; k <= n; k++) {
        for (int s = k; s <= n; s++) {
            ll sum = 0;
            for (int i = 1; i <= s - k + 1; i++)
                sum = (sum + f[i] * Q[s - i][k - 1]) % MOD;
            Q[s][k] = sum;
        }
    }
    for (int k = 1; k <= n; k++) {
        ll ans = Q[n][k] * curFact % MOD;
        cout << ans << "\n";
    }
    return 0;
}
