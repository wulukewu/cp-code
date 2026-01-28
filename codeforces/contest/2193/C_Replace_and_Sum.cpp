// ==================================================
// Problem   : 2193C - Replace and Sum
// Tags      : data structures, greedy
// Runtime   : 171 ms
// Memory    : 1000 KB
// URL       : https://codeforces.com/contest/2193/problem/C
// ==================================================

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
    int n, q;
    cin >> n >> q;
    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];
    vector<int>brr(n);
    FOR(i, 0, n) cin >> brr[i];

    vector<int>dp(n+1, 0);
    int m = 0;
    for(int i=n-1; i>=0; i--){
        m = max(m, arr[i]);
        m = max(m, brr[i]);
        // cout << "m=" << m << " i=" << i << endl;
        dp[i] = dp[i+1] + m;
    }
    // print(dp);

    FOR(qq, 0, q){
        int l, r;
        cin >> l >> r;

        int res = 0;
        // FOR(i, l-1, r){
        //     res = max(res, dp[i]);
        // }
        res = dp[l-1] - dp[r];
        cout << res << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
