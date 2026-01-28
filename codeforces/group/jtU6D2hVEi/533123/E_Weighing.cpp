// ==================================================
// Problem   : jtU6D2hVEiE - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/E
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
    int k, n;
    cin >> k >> n;

    int m = 0;
    vector < int > w(n);
    FOR(i, 0, n){
        cin >> w[i];
        m += w[i];
    }

    vector < vector < bool > > dp(n+1, vector < bool > (2*m+1, false));
    dp[0][m] = true;

    FOR(i, 0, n){
        int current = w[i];
        FOR(j, 0, 2*m+1){
            if(dp[i][j]){
                dp[i+1][j] = true;

                int idx_left = j - current;
                if(idx_left >= 0){
                    dp[i+1][idx_left] = true;
                }

                int idx_right = j + current;
                if(idx_right < 2*m+1){
                    dp[i+1][idx_right] = true;
                }
            }
        }
    }

    // FOR(i, 0, n+1){
    //     FOR(j, 0, 2*m+1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    if(k+m>=0 and k+m<2*m+1 and dp[n][k+m]){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
