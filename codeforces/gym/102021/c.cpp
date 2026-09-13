/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        102021C — Coolest Ski Route
 * Problem URL:    https://codeforces.com/gym/102021/problem/C
 *
 * Matched result: AC
 * Submission:     #387872040
 * Submission URL: https://codeforces.com/gym/102021/submission/387872040
 * Submitted:      2026-08-21 18:15:13 +0800
 * Language:       C++17 (GCC 7-32)
 * Runtime:        31 ms
 * Memory:         100.0 KiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2026-08-21 22:22:10 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
#ifdef LOCAL
template<class... T>void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define dbg(...) ((void)0)
#endif

using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9+7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b){a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res, a); timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b) {a = a * POW(b, MOD-2) % MOD;}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> map(n+1);
    FOR(i, 0, m){
        int u, v, c;
        cin >> u >> v >> c;
        map[u].PB({v, c});
    }

    vector<int>dp(n+1, -1);

    auto dfs = [&](auto &self, int u)-> int {
        if(dp[u] != -1){
            return dp[u];
        }

        int maxs = 0;
        for(auto &[v, c]: map[u]){
            maxs = max(maxs, c + self(self, v));
        }
        return dp[u] = maxs;
    };

    int ans = 0;
    FOR(i, 1, n+1){
        ans = max(ans, dfs(dfs, i));
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
