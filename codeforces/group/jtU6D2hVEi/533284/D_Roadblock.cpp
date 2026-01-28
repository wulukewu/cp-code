// ==================================================
// Problem   : jtU6D2hVEiD - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/D
// ==================================================

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
    int n, m;
    cin >> n >> m;

    const int INF = 1e18;

    vector < vector < int > > G(n+1);
    vector < vector < int > > dist(n+1, vector < int > (n+1, INF));
    FOR(i, 0, n+1) dist[i][i] = 0;
    int u, v, l;
    FOR(i, 0, m){
        cin >> u >> v >> l;
        G[u].PB(v);
        G[v].PB(u);
        // dist[u][v] = l;
        // dist[v][u] = l;
        dist[u][v] = min(dist[u][v], l);
        dist[v][u] = min(dist[v][u], l);
    }

    vector < int > d1(n+1, INF);
    vector < int > parent(n+1, -1);
    priority_queue < pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > pq;
    pq.push({0, 1});
    d1[1] = 0;

    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();

        int l = t.F;
        int u = t.S;

        if(l!=d1[u]) continue;
        // if(u==n-1){
        //     ans = l;
        //     break;
        // }

        for(int v: G[u]){
            if(d1[v]>l+dist[u][v]){
                d1[v] = l+dist[u][v];
                parent[v] = u;
                pq.push({d1[v], v});
            }
        }
    }

    // print(d1);

    int ori = d1[n];
    vector < pair < int, int > > path;
    int cur = n;
    while(cur!=1  and parent[cur]!=-1){
        path.EB(parent[cur], cur);
        cur = parent[cur];
    }
    // for(auto e: path) cout << e.F << ' ' << e.S << endl;

    int ans = 0;
    for(auto e: path){
        int a = e.F;
        int b = e.S;
        int d = dist[a][b];

        dist[a][b] = d * 2;
        dist[b][a] = d * 2;

        vector < int > d2(n+1, INF);
        priority_queue < pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > pq2;
        pq2.push({0, 1});
        d2[1] = 0;
        while(!pq2.empty()){
            auto t = pq2.top();
            pq2.pop();

            int l = t.F;
            int u = t.S;

            if(l!=d2[u]) continue;

            for(int v: G[u]){
                if(d2[v]>l+dist[u][v]){
                    d2[v] = l+dist[u][v];
                    pq2.push({d2[v], v});
                }
            }
        }

        // print(d2);

        ans = max(ans, d2[n]-ori);

        dist[a][b] = d;
        dist[b][a] = d;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
