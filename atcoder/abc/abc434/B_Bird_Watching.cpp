/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc434_b — Bird Watching
 * Problem URL:    https://atcoder.jp/contests/abc434/tasks/abc434_b
 *
 * Matched result: AC
 * Submission:     #71301438
 * Submission URL: https://atcoder.jp/contests/abc434/submissions/71301438
 * Submitted:      2025-11-29 20:05:19 +0800
 * Language:       C++23 (GCC 15.2.0)
 * Runtime:        2 ms
 * Points:         200.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-11-29 21:43:51 +0800
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

    vector < pair < int, int > > v(m);
    int a, b;
    FOR(i, 0, n){
        cin >> a >> b;
        v[a-1].F++;
        v[a-1].S += b;
    }

    FOR(i, 0, m){
        double ans = (double) v[i].S / v[i].F;
        cout << std::fixed << setprecision(15) << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
