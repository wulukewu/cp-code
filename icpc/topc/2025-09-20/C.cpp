#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define endl '\n'
//#define int long long
//#define float double
//#define float long double
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

void solve() {
    int n, m;
    cin >> n >> m;

    vector < vector < pair <int, int> > > G(n);
    vector < int > tra(m, 0);
    int x, y, v;
    FOR(i, 0, m){
        cin >> x >> y >> v;
        x--;
        y--;
        G[x].PB({y, i});
        G[y].PB({x, i});
        tra[i] = v;
    }

    FOR(i, 0, n){
        if(G[i].size()>1){
            reverse(ALL(G[i]));
        }
    }

    int ans = -1;
    auto dfs = [&](auto&& self, int x, int y) -> void {
        // cout << x << ' ' << y << endl;
        ans = max(ans, y);
        bool has_entered = false;
        for(auto i: G[x]){
            int v = tra[i.S];
            if(v>-1){
                has_entered = true;
                tra[i.S] = -1;
                self(self, i.F, y+v);
                tra[i.S] = v;
                break;
            }
            // if(i.S==false){
            //     has_entered = true;
            //     i.S = true;
            //     self(self, i.F, y+i.S);
            //     i.S = false;
            // }
        }
        // if(has_entered and x-1>=0){
        if(x-1>=0){
            self(self, x-1, y);
        }
    };

    dfs(dfs, n-1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
