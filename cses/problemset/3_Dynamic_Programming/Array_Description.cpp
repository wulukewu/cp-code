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
    int n, m;
    cin >> n >> m;

    vector < int > x(n);
    FOR(i, 0, n) cin >> x[i];

    int offs[3] = {-1, 0, 1};
    vector < vector < int > > dp(n+1, vector < int > (m+1, 0));

    FOR(i, 1, n+1){
        if(i==1){
            if(x[i-1]==0){
                FOR(j, 1, m+1){
                    dp[i][j] = 1;
                }
            }else{
                dp[i][x[i-1]] = 1;
            }
            continue;
        }
        if(x[i-1]==0){
            FOR(j, 1, m+1){
                for(int k: offs){
                    if(j+k>0 and j+k<=m){
                        dp[i][j] += dp[i-1][j+k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }else{
            for(int j: offs){
                if(x[i-1]+j>0 and x[i-1]+j<=m){
                    dp[i][x[i-1]] += dp[i-1][x[i-1]+j];
                    dp[i][x[i-1]] %= MOD;
                }
            }
        }
    }

    // FOR(i, 0, n+1){
    //     FOR(j, 0, m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    FOR(j, 1, m+1){
        ans += dp[n][j];
        ans %= MOD;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
