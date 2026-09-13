/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104059L — Lots of Land
 * Problem URL:    https://codeforces.com/gym/104059/problem/L
 *
 * Matched result: AC
 * Submission:     #388683020
 * Submission URL: https://codeforces.com/gym/104059/submission/388683020
 * Submitted:      2026-08-28 21:48:33 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        46 ms
 * Memory:         100.0 KiB
 * Submissions:    2 total / 1 accepted
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


void solve(){
    int l,w,n;
    cin >> l >> w >> n;
    if((l*w) % n != 0){
        cout << "impossible\n";
        return;
    }
    int a,b,d;
    for(int i=1;i*i<=n;i++){
        if(n%i != 0) continue;
        a = i;
        b = n/i;
        if(l%a == 0 && w % b == 0){
            a = l/a;
            b = w/b;
            d = w/b;
            break;
        }
        swap(a,b);
        if(l%a == 0 && w % b == 0){
            a = l/a;
            b = w/b;
            d = w/b;
            break;
        }
    }
    // cout << a << " " << b << endl;
    // x = 3*(l/a) + (w/b);
    
    // vector<vector<int>> grid(l,vector<int>(w));
    for(int i=0;i<l;i++){
        for(int j=0;j<w;j++){
            int num =  d*(i/a) + (j/b);
            char c = 'A' + num;
            cout << c;
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
