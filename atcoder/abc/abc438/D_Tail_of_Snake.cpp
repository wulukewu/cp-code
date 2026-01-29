// ==================================================
// Problem   : ABC438_D - Tail of Snake
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc438/tasks/abc438_d
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

    vector<vector<int>>v(3,vector<int>(n));
    FOR(i, 0, 3){
        FOR(j, 0, n){
            cin >> v[i][j];
        }
    }

    FOR(i, 1, n){
        v[0][i] += v[0][i-1];
    }
    v[1][1] += v[0][0];
    FOR(i, 2, n){
        v[1][i] += max(v[1][i-1], v[0][i-1]);
    }
    v[2][2] += v[1][1];
    FOR(i, 3, n){
        v[2][i] += max(v[2][i-1], v[1][i-1]);
    }

    // FOR(i, 0, 3){
    //     print(v[i]);
    // }

    cout << v[2][n-1] << endl;

    // vector<int>arr(n);
    // FOR(i, 0, n) cin >> arr[i];
    // vector<int>brr(n);
    // FOR(i, 0, n) cin >> brr[i];
    // vector<int>crr(n);
    // FOR(i, 0, n) cin >> crr[i];

    // vector<int>darr(n+1, 0);
    // FOR(i, 0, n) darr[i+1] = darr[i] + arr[i];
    // vector<int>dbrr(n+1, 0);
    // FOR(i, 0, n) dbrr[i+1] = dbrr[i] + brr[i];
    // vector<int>dcrr(n+1, 0);
    // FOR(i, 0, n) dcrr[i+1] = dcrr[i] + crr[i];
    // // print(darr);
    // // print(dbrr);
    // // print(dcrr);

    // int ans = 0;
    // FOR(x, 1, n){
    //     FOR(y, x+1, n){
    //         // cout << x << ' ' << y << endl;
    //         int a = darr[x];
    //         int b = dbrr[y]-dbrr[x];
    //         int c = dcrr[n]-dcrr[y];
    //         // cout << a << ' ' << b << ' ' << c << endl;
    //         int s = a + b + c;
    //         ans = max(ans, s);
    //     }
    // }
    // cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
