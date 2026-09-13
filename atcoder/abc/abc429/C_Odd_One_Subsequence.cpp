/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc429_c — Odd One Subsequence
 * Problem URL:    https://atcoder.jp/contests/abc429/tasks/abc429_c
 *
 * Matched result: AC
 * Submission:     #70421695
 * Submission URL: https://atcoder.jp/contests/abc429/submissions/70421695
 * Submitted:      2025-10-25 20:08:45 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        136 ms
 * Points:         300.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-10-25 21:42:27 +0800
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

void solve() {
    int n;
    cin >> n;

    vector < int > v(n);
    FOR(i, 0, n) cin >> v[i];

    map < int, int > mp;
    FOR(i, 0, n){
        if(mp.find(v[i])==mp.end()){
            mp.insert({v[i], 1});
        }else{
            mp[v[i]]++;
        }
    }

    int ans = 0;
    for(auto i: mp){
        if(i.S>1){
            ans += (i.S * (i.S-1))/2 * (n-i.S);
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
