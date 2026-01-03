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
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
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

void solve(){
    int n;
    cin >> n;
 
    vector<pair<int, int>>v(n);
    FOR(i, 0, n) cin >> v[i].F >> v[i].S;

    sort(ALL(v), [](pair<int, int> &a, pair<int, int> &b){
        if(a.F!=b.F){
            return a.F < b.F;
        }else{
            return a.S > b.S;
        }
    });

    // FOR(i, 0, n){
    //     cout << v[i].F << ' ' << v[i].S << endl;
    // }
    // cout << endl;

    vector<int>ans;

    FOR(i, 0, n){
        // print(ans);
        int curb = v[i].S;
        if(ans.empty() or curb > ans.back()){
            ans.PB(curb);
        }else{
            auto it = lower_bound(ALL(ans), curb);
            *it = curb;
        }
    }
    cout << ans.size() << endl;

    // vector<pair<int, int>>dp(n, {0, 0});
    // dp[0] = {1, v[0].S};
    // FOR(i, 0, n-1){
    //     if(v[i+1].F>v[i].F){
    //         if(v[i+1].S>dp[i].S){
    //             dp[i+1].F = dp[i].F + 1;
    //             dp[i+1].S = v[i+1].S;
    //         }else{
    //             dp[i+1].F = dp[i].F;
    //             dp[i+1].S = dp[i].S;
    //         }
    //     }else{
    //         // v[i+1].F == v[i].F
    //         dp[i+1] = dp[i];
    //     }
    // }

    // FOR(i, 0, n){
    //     cout << dp[i].F << ' ' << dp[i].S << endl;
    // }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
