#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll mod_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<bool> vis(n + 1, false);
    vector<int> spf(n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= n; i++)
        if (spf[i] == i)
            for (int j = i * i; j <= n; j += i)
                if (spf[j] == j) spf[j] = i;
    auto factor = [&](int x) {
        vector<pair<int,int>> res;
        while (x > 1) {
            int p = spf[x], cnt = 0;
            while (x % p == 0) { x /= p; cnt++; }
            res.push_back({p, cnt});
        }
        return res;
    };
    map<int,int> max_exp;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int len = 0, cur = i;
        do {
            vis[cur] = true;
            cur = p[cur];
            len++;
        } while (cur != i);
        auto f = factor(len);
        for (auto &[pr, e] : f)
            max_exp[pr] = max(max_exp[pr], e);
    }
    ll ans = 1;
    for (auto &[pr, e] : max_exp)
        ans = ans * mod_pow(pr, e) % MOD;
    cout << ans << "\n";
    return 0;
}
