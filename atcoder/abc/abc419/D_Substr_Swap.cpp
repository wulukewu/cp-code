/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc419_d — Substr Swap
 * Problem URL:    https://atcoder.jp/contests/abc419/tasks/abc419_d
 *
 * Matched result: AC
 * Submission:     #68546538
 * Submission URL: https://atcoder.jp/contests/abc419/submissions/68546538
 * Submitted:      2025-08-16 20:29:35 +0800
 * Language:       C++ 20 (gcc 12.2)
 * Runtime:        32 ms
 * Points:         400.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-08-16 21:33:08 +0800
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
//#define int long long
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
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector < int > dp(n+1, 0);
    int l, r;
    FOR(i, 0, m){
        cin >> l >> r;
        dp[l-1]++;
        dp[r]--;
    }
    FOR(i, 1, n+1){
        dp[i] += dp[i-1];
    }
    // print(dp);

    FOR(i, 0, n){
        if(dp[i]%2==0){
            cout << s[i];
        }else{
            cout << t[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
