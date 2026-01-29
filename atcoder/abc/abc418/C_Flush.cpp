// ==================================================
// Problem   : ABC418_C - Flush
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc418/tasks/abc418_c
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
    int n, q;
    cin >> n >> q;

    // int m = 0;
    int max_a = 0;
    vector < int > arr(n);
    FOR(i, 0, n){
        cin >> arr[i];
        // m += arr[i];
        max_a = max(max_a, arr[i]);
    }

    const int m = 1000005;

    vector < int > brr(m+1, 0);
    FOR(i, 0, n){
        brr[1]++;
        brr[arr[i]+1]--;
    }
    FOR(i, 2, m+1){
        brr[i] += brr[i-1];
    }
    FOR(i, 2, m+1){
        brr[i] += brr[i-1];
    }
    // print(brr);

    int b;
    while(q--){
        cin >> b;
        if(b>max_a){
            cout << -1 << endl;
        }else{
            cout << brr[b-1]+1 << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
