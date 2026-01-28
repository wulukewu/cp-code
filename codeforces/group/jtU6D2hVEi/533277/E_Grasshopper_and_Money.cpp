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
    int n, k;
    cin >> n >> k;

    vector < int > coins(n-2);
    FOR(i, 0, n-2) cin >> coins[i];

    vector < pair < int, vector < int > > > dp(n);
    dp[0] = make_pair(0, vector < int >());
    FOR(i, 1, n){
        int max_coins = -INT_MAX;
        int max_coins_idx = -1;
        FOR(j, 1, k+1){
            if(i-j<0) break;
            // max_coins = max(max_coins, dp[i-j].F);
            if(dp[i-j].F>max_coins){
                max_coins = dp[i-j].F;
                max_coins_idx = i-j;
            }
        }

        if(i<n-1){
            dp[i].F = max_coins + coins[i-1];
        }else{
            dp[i].F = max_coins;
        }

        // cout << "max_coins_idx " << max_coins_idx << endl;
        
        vector < int > v = dp[max_coins_idx].S;
        v.PB(max_coins_idx+1);
        dp[i].S = v;
        // for(int j: v){
        //     cout << j << ' ';
        // }
        // cout << endl;
    }

    // print(dp);
    cout << dp[n-1].F << endl;
    cout << dp[n-1].S.size() << endl;
    for(int i: dp[n-1].S){
        cout << i << ' ';
    }
    cout << n << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
