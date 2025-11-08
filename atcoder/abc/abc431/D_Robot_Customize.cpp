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

    vector < int > w(n);
    vector < int > h(n);
    vector < int > b(n);
    FOR(i, 0, n) cin >> w[i] >> h[i] >> b[i];

    int sum_w = 0, sum_h = 0, sum_b = 0;
    FOR(i, 0, n){
        sum_w += w[i];
        sum_h += h[i];
        sum_b += b[i];
    }

    int m = sum_w / 2;
    vector < vector < int > > dp(n+1, vector < int > (m+1, 0));
    FOR(i, 1, n+1){
        int a = h[i-1] - b[i-1];
        FOR(j, 1, m+1){
            dp[i][j] = dp[i-1][j];
            if(j-w[i-1]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+a);
            }
        }
    }

    // cout << sum_b << endl;
    // FOR(i, 0, n+1) print(dp[i]);

    int ans = 0;
    FOR(j, 0, m+1){
        ans = max(ans, dp[n][j]);
    }
    ans += sum_b;
    cout << ans << endl;

    // int m = 0;
    // FOR(i, 0, n) m += w[i];
    // m /= 2;

    // vector < vector < int > > dp(n+1, vector < int > (m+1, 0));

    // FOR(i, 1, n+1){
    //     FOR(j, 1, m+1){
    //         dp[i][j] = dp[i-1][j]+b[i-1];
    //         if(h[i-1]>=b[i-1] and j-w[i-1]>=0){
    //             dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+h[i-1]);
    //         }
    //         // if(h[i-1]<b[i-1]){
    //         //     dp[i][j] = dp[i-1][j]+b[i-1];
    //         // }else if(j-w[i-1]>=0){
    //         //     dp[i][j] = max(dp[i-1][j]+b[i-1], dp[i-1][j-w[i-1]]+h[i-1]);
    //         // }else{
    //         //     dp[i][j] = dp[i-1][j]+b[i-1];
    //         // }
    //     }
    // }

    // FOR(i, 0, n+1) print(dp[i]);

    // if(m==0){
    //     cout << b[0] << endl;
    // }else{
    //     // cout << dp[n][m] << endl;
    //     int ans = 0;
    //     FOR(i, 0, m+1){
    //         ans = max(ans, dp[n][i]);
    //     }
    //     cout << ans << endl;
    // }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
