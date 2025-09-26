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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b){a = (a+b)%MOD;}
void submod(ll &a, ll b){a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b){a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}

template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector < vector < pair < int, int > > > G(n);
    int u, v, w;
    FOR(i, 0, m){
        cin >> u >> v >> w;
        u--; v--;
        G[u].PB({v, w});
        G[v].PB({u, w});
    }

    vector < bool > visit(n, false);
    visit[0] = true;

    int ans = LLONG_MAX;
    auto dfs = [&](auto&& self, int x, int y, int z) -> void {
        if(x==n-1){
            ans = min(ans, y);
            return;
        }

        for(auto i: G[x]){
            // cout << i.F << ' ' << i.S << endl;
            if(visit[i.F]==false){
                visit[i.F] = true;
                if(z>i.S){
                    self(self, i.F, y+i.S, z-i.S);
                }else if(z==i.S){
                    self(self, i.F, y+i.S+b, a);
                }else{
                    self(self, i.F, y+z+b+i.S, a-i.S);
                }
                visit[i.F] = false;
            }
        }
    };

    dfs(dfs, 0, 0, a);
    if(ans==LLONG_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}