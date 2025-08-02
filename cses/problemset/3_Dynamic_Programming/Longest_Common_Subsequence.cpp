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
    int n, m;
    cin >> n >> m;
    
    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];
    vector < int > brr(m);
    FOR(i, 0, m) cin >> brr[i];

    vector < vector < int > > dp(n+1, vector < int > (m+1, 0));
    // vector < vector < int > > arrow(n+1, vector < int > (m+1, 0));
    FOR(i, 0, n){
        FOR(j, 0, m){
            if(arr[i]==brr[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
            // if(arr[i]==brr[j]){
            //     dp[i+1][j+1] = dp[i][j] + 1;
            //     arrow[i+1][j+1] = 1;
            // }else if(dp[i+1][j]>dp[i][j+1]){
            //     dp[i+1][j+1] = dp[i+1][j];
            //     arrow[i+1][j+1] = 2;
            // }else{
            //     dp[i+1][j+1] = dp[i][j+1];
            //     arrow[i+1][j+1] = 3;
            // }
        }
    }

    // FOR(i, 0, n+1){
    //     print(dp[i]);
    // }
    // FOR(i, 0, n+1){
    //     print(arrow[i]);
    // }

    cout << dp[n][m] << endl;

    stack < int > ans;
    int x = n, y = m;
    while(!(x==0 or y==0)){
        // if(arrow[x][y]==1){
        //     ans.push(arr[x-1]);
        //     x--;
        //     y--;
        // }else if(arrow[x][y]==2){
        //     x--;
        // }else{
        //     y--;
        // }
        if(dp[x][y]>dp[x-1][y] and dp[x][y]>dp[x][y-1]){
            ans.push(arr[x-1]);
            x--;
            y--;
        }else if(dp[x][y]>dp[x-1][y]){
            y--;
        }else{
            x--;
        }
    }
    // cout << x << ' ' << y << endl;
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
