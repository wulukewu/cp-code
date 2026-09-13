/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        2184A — Social Experiment
 * Problem URL:    https://codeforces.com/contest/2184/problem/A
 *
 * Matched result: AC
 * Submission:     #357465589
 * Submission URL: https://codeforces.com/contest/2184/submission/357465589
 * Submitted:      2026-01-12 22:43:13 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        31 ms
 * Memory:         0 B
 * Rating:         800
 * Tags:           math
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
    int n;
    cin >> n;

    if(n<=3){
        cout << n << endl;
    }else if(n%2==1){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }

    // if(n%3==0 or n%2==0){
    //     cout << 0 << endl;
    // }else if(n%5==0){
    //     cout << 1 << endl;
    // }else if(n%2==0){
    //     cout << 2 << endl;
    // }else if(n%3==0){
    //     cout << 3 << endl;
    // }else{

    // }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
