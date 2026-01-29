// ==================================================
// Problem   : CSES - Grid Paths I
// URL       : https://cses.fi/problemset/task/1638
// ==================================================

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

void solve() {
    int n;
    cin >> n;

    vector < vector < char > > arr(n, vector < char > (n));
    FOR(i, 0, n){
        FOR(j, 0, n){
            cin >> arr[i][j];
        }
    }

    vector < vector < int > > dp(n+1, vector < int > (n+1, 0));
    // FOR(i, 0, n+1) dp[i][0] = 1;
    // FOR(j, 0, n+1) dp[0][j] = 1;
    dp[1][1] = 1;

    FOR(i, 0, n){
        FOR(j, 0, n){
            if(arr[i][j]=='.'){
                dp[i+1][j+1] += dp[i][j+1] + dp[i+1][j];
                dp[i+1][j+1] %= MOD;
            }else{
                dp[i+1][j+1] = 0;
            }
        }
    }

    // FOR(i, 0, n+1){
    //     FOR(j, 0, n+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][n] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
