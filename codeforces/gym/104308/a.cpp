// ==================================================
// Problem   : 104308A - Unknown
// Submission Result: Runtime of 62 ms and Memory usage of 0 KB
// Runtime   : 62 ms
// Memory    : 0 KB
// URL       : https://codeforces.com/contest/104308/problem/A
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
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
ll POW(ll a, ll b) { ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1);return res;}
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;

    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];

    int h = arr[0];
    int ans = 0;
    FOR(i, 1, n){
        if(arr[i]>h){
            h = arr[i];
        }else{
            ans += h-arr[i];
        }
        // cout << ans << endl;
    }

    int h2 = arr[n-1];
    for(int i=n-1; i>=0; i--){
        if(arr[i]==h) break;
        ans -= h-arr[i];
        if(arr[i]>h2){
            h2 = arr[i];
        }else{
            ans += h2-arr[i];
        }
        // cout << ans << endl;
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}