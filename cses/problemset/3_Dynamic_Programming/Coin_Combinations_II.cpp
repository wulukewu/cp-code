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
    int n, x;
    cin >> n >> x;

    vector < int > c(n);
    FOR(i, 0, n) cin >> c[i];

    vector < int > dp(x+1, 0);
    dp[0] = 1;
    for(int i: c){
        for(int j=1; j<=x; j++){
            if(j-i>=0){
                dp[j] += dp[j-i];
                dp[j] %= MOD;
            }
        }
    }

    // FOR(i, 0, x+1){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
