// ==================================================
// Problem   : 533280P - Unknown
// URL       : https://codeforces.com/contest/533280/problem/P
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
    ifstream fcin("input.txt");
    ofstream fcout("output.txt");

    int n;
    fcin >> n;

    int m = 0;
    vector < int > arr(n);
    FOR(i, 0, n){
        fcin >> arr[i];
        m += arr[i];
    }
    
    if(m%2==1){
        fcout << "NO" << endl;
        return;
    }
    m /= 2;

    vector < vector < int > > dp(n+1, vector < int > (m+1, 0));
    FOR(i, 0, n+1) dp[i][m] = 0;
    FOR(j, 0, m+1){
        if(j>=arr[0]) dp[0][j] = arr[0];
        else dp[0][j] = 0;
    }

    FOR(i, 1, n){
        FOR(j, 1, m+1){
            dp[i][j] = dp[i-1][j];
            if(j-arr[i-1]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i-1]]+arr[i-1]);
            }
        }
    }

    // FOR(i, 0, n){
    //     print(dp[i]);
    // }

    if(dp[n-1][m] == m){
        fcout << "YES" << endl;
    }else{
        fcout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
