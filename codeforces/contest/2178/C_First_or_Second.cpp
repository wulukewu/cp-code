// ==================================================
// Problem   : 2178C - First or Second
// Tags      : dp, greedy, implementation
// Submission Result: Runtime of 93 ms and Memory usage of 900 KB
// Runtime   : 93 ms
// Memory    : 900 KB
// URL       : https://codeforces.com/contest/2178/problem/C
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

    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];

    vector<int>dp1(n+1,0);
    FOR(i, 0, n) dp1[i+1] = dp1[i] + arr[i];
    vector<int>dp2(n+1,0);
    FOR(i, 0, n) dp2[i+1] = dp2[i] + abs(arr[i]);
    
    // print(dp1);
    // print(dp2);

    int ans = -LLONG_MAX;
    FOR(i, 0, n){
        int x = dp2[i];
        int y = dp1[n] - dp1[i+1];
        // cout << x << ' ' << y << endl;
        int z = x - y;
        if(i>0 and arr[0]<0){
            z += arr[0] * 2;
        }
        ans = max(ans, z);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
