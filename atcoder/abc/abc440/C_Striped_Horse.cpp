/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc440_c — Striped Horse
 * Problem URL:    https://atcoder.jp/contests/abc440/tasks/abc440_c
 *
 * Matched result: AC
 * Submission:     #72356297
 * Submission URL: https://atcoder.jp/contests/abc440/submissions/72356297
 * Submitted:      2026-01-10 20:25:15 +0800
 * Language:       C++23 (GCC 15.2.0)
 * Runtime:        12 ms
 * Points:         300.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2026-01-10 21:57:20 +0800
 * Match policy:   matched by contest path and filename/title; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
//#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
template <typename T>
void printQ(queue < T > q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
template <typename T>
void printPQ(priority_queue < T > pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void solve(){
    int n, w;
    cin >> n >> w;
    vector<int>c(n);
    FOR(i, 0, n) cin >> c[i];

    int w2 = 2*w;
    vector<int>v(w2, 0);
    FOR(i, 0, n){
        v[i%w2] += c[i];
    }
    // print(v);

    int ans = 0;
    FOR(i, 0, w){
        ans += v[i];
    }
    int res = ans;
    FOR(i, 0, w2){
        res += v[(i+w)%w2];
        res -= v[i];
        // cout << res << endl;
        ans = min(ans, res);
    }
    cout << ans << endl;

    // vector<bool>v(n, false);
    // FOR(i, 0, n){
    //     if(c[i]%(2*w)<w){
    //         v[i] = true;
    //     }
    // }
    // print(v);

    // int ans = LLONG_MAX;
    // FOR(x, 0, n){
    //     int s = 0;
    //     FOR(i, 0, n){

    //     }
    // }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
