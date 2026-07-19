#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;
const int N = 2000005;
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
    vector<pair<int,int>> traps(m);
    for (int i = 0; i < m; i++) cin >> traps[i].first >> traps[i].second;
    traps.push_back({n, n});
    sort(traps.begin(), traps.end());
    vector<ll> dp(m + 1, 0);
    for (int i = 0; i <= m; i++) {
        dp[i] = C(traps[i].first + traps[i].second - 2, traps[i].first - 1);
        for (int j = 0; j < i; j++) {
            if (traps[j].first <= traps[i].first && traps[j].second <= traps[i].second) {
                int dx = traps[i].first - traps[j].first;
                int dy = traps[i].second - traps[j].second;
                ll sub = dp[j] * C(dx + dy, dx) % MOD;
                dp[i] = (dp[i] - sub + MOD) % MOD;
            }
        }
    }
    cout << dp[m] << "\n";
    return 0;
}
