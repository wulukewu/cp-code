#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
#ifdef LOCAL
template<class.. T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' ', ...));
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define dbg(...) ((void)0)
#endif

using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T>using Prior = priority_queue<T>;
template<typename T>using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e9-7;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, pair<int, int>>>>G(n);
    FOR(i, 0, m){
        int u, v, t, h;
        cin >> u >> v >> t >> h;
        u--; v--;
        G[u].PB({v, {t, h}});
        G[v].PB({u, {t, h}});
    }

    const int INF = (1ll<<60);
    vector<int>dp(n, -INF);
    Prior<pair<int, int>>pq;
    dp[0] = INF;
    pq.push({INF, 0});
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        // cout << d << ' ' << u << endl;

        if(dp[u]!=d) continue;
        for(auto e: G[u]){
            // auto [v, th] = e;
            // auto [t, h] = th;
            int v = e.F;
            int t = e.S.F;
            int h = e.S.S;
            int nd = min(dp[u]-t, h-t);
            if(nd>dp[v]){
                dp[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    FOR(i, 0, n){
        if(dp[i]>=0){
            cout << 1;
        }else{
            cout << 0;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}