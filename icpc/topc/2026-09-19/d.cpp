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
    int n;
    cin >> n;
    vector<int>a(n);
    FOR(i, 0, n){
        cin >> a[i];
        a[i]--;
    }
    vector<int>b(n);
    FOR(i, 0, n){
        cin >> b[i];
        b[i]--;
    }
    vector<int>c(n);
    FOR(i, 0, n){
        cin >> c[i];
    }

    vector<pair<int, pair<int, int>>>edges;
    FOR(i, 0, n-1){
        edges.PB({a[i+1], {a[i], 0}});
    }
    FOR(i, 0, n-1){
        edges.PB({b[i], {b[i+1], c[b[i+1]]-c[b[i]]}});
    }

    vector<int>x(n, 0);
    FOR(i, 0, n){
        bool det = false;
        for(auto e: edges){
            int u = e.F;
            int v = e.S.F;
            int w = e.S.S;
            if(x[v]<x[u]+w){
                x[v]=x[u]+w;
                det = true;
                if(x[v]>c[v]){
                    cout << "No" << endl;
                    return;
                }
            }
        }
        if(!det){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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