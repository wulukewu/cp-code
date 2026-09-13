/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104059I — Improving IT
 * Problem URL:    https://codeforces.com/gym/104059/problem/I
 *
 * Matched result: AC
 * Submission:     #388690215
 * Submission URL: https://codeforces.com/gym/104059/submission/388690215
 * Submitted:      2026-08-28 23:04:02 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        171 ms
 * Memory:         200.0 KiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2026-08-28 23:41:51 +0800
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
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

#ifdef LOCAL
template<class...  T> void dbg(T... x) {
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
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b) % MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res, a);timesmod(a,a);}while(b>>=1);return res;}
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}

const ll INF = 1e15;

// 1000
// 100  800x
// 200  200
// 100  300
//      400
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> dp(n+2,INF);
    for(int i=1;i<=n;i++){
        int get , num_sell = min(m,n-i+1) , sell;
        cin >> get;
        // cout << get << " ";
        if(i == 1) dp[1] = get;
        else dp[i] += get;
        for(int j=1;j<=num_sell;j++){
            cin >> sell;
            int cost = get - sell;
            // cout << sell << " ";
            dp[i+j] = min(dp[i+j] , dp[i] - sell);
        }
        // cout << endl;
    }
    cout << dp[n+1] << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
