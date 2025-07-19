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

void solve() {
    int h, w;
    cin >> h >> w;

    vector < vector < int > > arr(h ,vector < int > (w));
    FOR(i, 0, h){
        FOR(j, 0, w){
            cin >> arr[i][j];
        }
    }

    vector < int > p(h+w-1);
    FOR(i, 0, h+w-1) cin >> p[i];

    vector < vector < int > > dp(h, vector < int > (w, LLONG_MAX));
    dp[h-1][w-1] = 0;
    for(int i=h-1; i>=0; i--){
        for(int j=w-1; j>=0; j--){
            if(i<h-1) dp[i][j] = min(dp[i][j], dp[i+1][j]);
            if(j<w-1) dp[i][j] = min(dp[i][j], dp[i][j+1]);
            dp[i][j] = max((int)0, dp[i][j]+p[i+j]-arr[i][j]);
        }
    }

    // FOR(i, 0, h){
    //     FOR(j, 0, w){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[0][0] << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
