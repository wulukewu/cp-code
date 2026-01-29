// ==================================================
// Problem   : 105168G2 - Unknown
// URL       : https://codeforces.com/contest/105168/problem/G2
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
// #define float double
// #define float long double
#define FOR(i, a ,b) for(int i = a; i< b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 998244353;
void pmod(ll &a, ll b) {a = (a+b)%MOD;}
void mmod(ll &a, ll b) {a = (a-b+MOD)%MOD;} 
void tmod(ll &a, ll b) {a = (a*b)%MOD;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b);}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)tmod(res,a);tmod(a,a);}while(b>>=1); return res;}
const double EPS = 1e-9;
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

const int MAXN = 2e5 + 5;

int fact[MAXN], invfact[MAXN];

void calculateFactorial(int n){
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[n] = POW(fact[n], MOD-2);
    for(int i = n-1; i >= 0; i--){
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
}

vector<int> G[MAXN];
int sz[MAXN];
int dp[MAXN];

void dfs(int u, int p){
    sz[u] = 1;
    dp[u] = 1;
    for(auto nxt: G[u]){
        if(nxt == p){
            continue;
        }

        dfs(nxt, u);
        sz[u] += sz[nxt];
        dp[u] = (dp[u] * dp[nxt]) % MOD;
        dp[u] = (dp[u] * invfact[sz[nxt]]) % MOD;
    }

    dp[u] = (dp[u] * fact[sz[u] - 1]) % MOD;
}


void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        G[i].clear();
        sz[i] = 0;
        dp[i] = 0;
    }

    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    dfs(1, -1);

    cout << dp[1] << endl;
    
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);

    calculateFactorial(MAXN - 1);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}