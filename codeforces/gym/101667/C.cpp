#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin() v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;

template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b + MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}


void solve(){
    int n, m;
    cin >> n >> m;

    vector < vector < int > > G(n);
    int u, v;
    FOR(i, 0, m){
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    vector < int > edge(n);
    FOR(i, 0, n){
        edge[i] = G[i].size();
    }

    int ans = -1;
    vector < bool > visit(n, false);
    auto dfs = [&](auto&& self, int x, int y) -> void {
        for(int i: G[x]){
            if(!visit[i] and edge[i]>edge[x]){
                visit[i] = true;
                self(self, i, y+1);
                visit[i] = false;
            }
        }
        // cout << y << endl;
        ans = max(ans, y);
    };

    int mn = INT_MAX;
    FOR(i, 0, n){
        mn = min(mn, edge[i]);
    }

    FOR(i, 0, n){
        if(edge[i]==mn){
            dfs(dfs, i, 1);
        }
    }

    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}