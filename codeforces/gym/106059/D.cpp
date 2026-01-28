// ==================================================
// Problem   : 106059D.cpp - Unknown
// URL       : https://codeforces.com/contest/106059/problem/D.cpp
// ==================================================

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
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1;; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector < vector < int > > G(n);
    int u, v;
    FOR(i, 0, n-1){
        cin >> u >> v;
        u--;
        v--;
        G[u].PB(v);
        G[v].PB(u);
    }

    FOR(qq, 0, q){
        int ans = 0;
        vector < int > visit(n, -1);
        int a, b;
        FOR(i, 0, 2){
            cin >> a >> b;
            a--;
            b--;
            vector < int > dir(n, -1);
            prior < pair < int, int > > pq;
            pq.push({0, a});
            // visit[a] = i;
            while(!pq.empty()){
                auto t = pq.top();
                pq.pop();
                cout << t.F << ' ' << t.S << endl;

                if(t.S==b){
                    ans += t.F;
                    cout << "break" << endl;
                    break;
                }

                // print(G[t.S]);
                if(visit[t.F]==-1){
                    for(int j: G[t.S]){
                        pq.push({t.F+1, j});
                        dir[j] = t.S;
                    }
                }else if(visit[t.F]!=i){
                    for(int j: G[t.S]){
                        pq.push({t.F, j});
                        dir[j] = t.S;
                        visit[t.F] = i;
                    }
                }else{
                    continue;
                }
                visit[t.F] = i;
            }

            if(i>0) continue;
            // visit = vector < int > (n, -1);
            FOR(i, 0, n) visit[i] = -1;
            // int x = b;
            // while(true){
            //     visit[x] = i;
            //     x = dir[x];
            //     if(x==a) break;
            // }
        }
        cout << ans << endl;
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}