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

    int max_r = 0;
    int min_r = INT_MAX;
    int max_c = 0;
    int min_c = INT_MAX;

    int r, c;
    FOR(i, 0, n){
        cin >> r >> c;
        max_r = max(max_r, r);
        min_r = min(min_r, r);
        max_c = max(max_c, c);
        min_c = min(min_c, c);
    }

    int mid_r = (min_r + max_r) / 2;
    int mid_c = (min_c + max_c) / 2;
    int ans = max(max(abs(min_r-mid_r), abs(max_r-mid_r)), max(abs(min_c-mid_c), abs(max_c-mid_c)));
    cout << ans << endl;

    // vector < pair < int, int > > v(n);
    // FOR(i, 0, n) cin >> v[i].F >> v[i].S;

    // int sum_r = 0;
    // int sum_c = 0;
    // FOR(i, 0, n){
    //     sum_r += v[i].F;
    //     sum_c += v[i].S;
    //     // cout << v[i].F + v[i].S << endl;
    // }
    // sum_r /= n;
    // sum_c /= n;
    // // cout << sum_r << ' ' << sum_c << endl;

    // int ans = 0;
    // FOR(i, 0, n){
    //     ans = max(ans, max(abs(sum_r-v[i].F), abs(sum_c-v[i].S)));
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
