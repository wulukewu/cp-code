/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        2184D — Unfair Game
 * Problem URL:    https://codeforces.com/contest/2184/problem/D
 *
 * Matched result: AC
 * Submission:     #357603667
 * Submission URL: https://codeforces.com/contest/2184/submission/357603667
 * Submitted:      2026-01-13 00:42:54 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        250 ms
 * Memory:         0 B
 * Rating:         1600
 * Tags:           combinatorics, dp, math
 * Submissions:    1 total / 1 accepted
 * File commit:    2026-01-13 01:29:25 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
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
    // vector<int>fac(1, 1);
    // int x = 1;
    // FOR(i, 2, 14){
    //     fac.PB(x);
    //     x *= i;
    // }
    // print(fac);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        int m = 0;
        int nn = n;
        while(nn>1){
            nn/=2;
            m++;
        }
        // cout << m << endl;

        // if(m<k){
        //     cout << 0 << endl;
        //     continue;
        // }

        int ans = 0;
        FOR(i, 0, m){
            if(k<i+1) continue;
            FOR(j, 0, min(k-i-1, i)+1){
                int a = i, b = min(j, i-j);
                int res = 1;
                FOR(k, 0, b) res *= a-k;
                FOR(k, 0, b) res /= k+1;
                // res *= fac[i];
                // res /= fac[j];
                // res /= fac[i-j];
                ans += res;
            }
        }
        cout << n-ans-(m+1<=k) << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
