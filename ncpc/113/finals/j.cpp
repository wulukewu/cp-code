#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res = 1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b){a = a*POW(b, MOD-2) % MOD;}
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}

struct DSU{
    int n;
    vector<int>p, r;
    DSU(int n=0): n(n), p(n), r(n, 0) {iota(ALL(p), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};


void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    FOR(i, 0, m){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    vector<int> weight(m, 1);
    FOR(i, 0, min(m, n-1)){
        weight[i] = 0;
    }

    vector<int> idx(m);
    iota(ALL(idx), 0);
    sort(ALL(idx), [&](int a,int b){
        if(weight[a] != weight[b]) return weight[a] > weight[b];
        return a < b;
    });

    DSU dsu(n);
    int used = 0;
    int used_nonT1 = 0;
    for(int id : idx){
        int u = edges[id].first;
        int v = edges[id].second;
        if(dsu.unite(u, v)){
            used++;
            if(weight[id] == 1) used_nonT1++;
            if(used == n-1) break;
        }
    }

    cout << used_nonT1 << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}

