// ==================================================
// Problem   : 2193D - Monster Game
// Tags      : binary search, sortings, two pointers
// Submission Result: Runtime of 109 ms and Memory usage of 0 KB
// Runtime   : 109 ms
// Memory    : 0 KB
// URL       : https://codeforces.com/contest/2193/problem/D
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
    int n;
    cin >> n;
    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];
    vector<int>brr(n);
    FOR(i, 0, n) cin >> brr[i];

    sort(ALL(arr));
    FOR(i, 0, n-1) brr[i+1] += brr[i];

    int ans = 0;
    FOR(i, 0, n){
        int sw = brr[i];
        if(sw>n) break;
        int diff = arr[n-sw];
        int score = diff * (i+1);
        ans = max(ans, score);
    }
    cout << ans << endl;

    // int ans = 0;
    // int l = 0;
    // int r = 1e9+10;
    // while(l<=r){
    //     int mid = l + (r-l)/2;
    //     int a = lower_bound(ALL(arr), mid) - arr.begin();
    //     a = n - a;
    //     // cout << mid << ' ' << a << endl;
    //     int b = lower_bound(ALL(brr), a) - brr.begin();
    //     // cout << b << endl;
    //     // ans = max(ans, mid*b);
    //     int score = mid * b;
    //     cout << "score=" << score << endl;
    //     if(score>ans){
    //         l = mid + 1;
    //         ans = score;
    //     }else{
    //         r = mid - 1;
    //     }
    // }
    // cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
