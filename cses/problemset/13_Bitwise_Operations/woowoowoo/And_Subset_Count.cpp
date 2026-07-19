#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll fp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int N = 20;
    vector<ll> dp(1 << N, 0);
    vector<ll> dp2(1 << N, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp[x]++;
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < (1 << N); j++)
            if (j & (1 << i))
                dp[j ^ (1 << i)] += dp[j];
    for (int i = 0; i < (1 << N); i++)
        dp2[i] = (fp(2, dp[i]) - 1 + mod) % mod;
    for (int i = 0; i < N; i++)
        for (int j = (1 << N) - 1; j > 0; j--)
            if (j & (1 << i)) {
                dp2[j ^ (1 << i)] -= dp2[j];
                if (dp2[j ^ (1 << i)] < 0)
                    dp2[j ^ (1 << i)] += mod;
            }
    for (int i = 0; i <= n; i++)
        cout << dp2[i] << " ";
    cout << '\n';
    return 0;
}
