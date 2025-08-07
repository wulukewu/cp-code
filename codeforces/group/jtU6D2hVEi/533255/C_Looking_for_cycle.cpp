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
    int n, m;
    cin >> n >> m;

    vector < vector < int > > G(n);
    int v, u;
    FOR(i, 0, m){
        cin >> v >> u;
        G[v-1].PB(u);
        // G[u-1].PB(v);
    }

    bool ans = false;
    int start = -1;
    int end = -1;
    vector < int > visit(n, 0);
    vector < int > parent(n, -1);

    auto dfs = [&](auto&& self, int x) -> bool {
        visit[x-1] = 1;

        for(int y: G[x-1]){
            if(visit[y-1]==1){
                start = y;
                end = x;
                return true;
            }
            if(visit[y-1]==0){
                parent[y-1] = x;
                if(self(self, y)){
                    return true;
                }
            }
        }

        visit[x-1] = 2;
        return false;
    };

    FOR(i, 1, n+1){
        if(visit[i-1]==0){
            if(dfs(dfs, i)){
                ans = true;
                break;
            }
        }
    }

    if(ans){
        cout << "YES" << endl;
        // cout << start << ' ' << end << endl;
        // print(parent);

        int x = end;
        vector < int > cycle;
        while(x!=start){
            cycle.PB(x);
            x = parent[x-1];
        }
        cycle.PB(x);
        reverse(ALL(cycle));
        print(cycle);
    }else{
        cout << "NO" << endl;
    }

    // int ans = -1;
    // vector < bool > visit(n, false);
    // vector < int > parent(n, -1);

    // auto dfs = [&](auto&& self, int x, int p) -> void {
    //     // print(visit);
    //     if(ans!=-1) return;
    //     for(int y: G[x-1]){
    //         if(visit[y-1] and p!=1){
    //             ans = y;
    //             parent[x-1] = y;
    //             return;
    //         }else{
    //             visit[y-1] = true;
    //             parent[x-1] = y;
    //             self(self, y, x);
    //             if(ans!=-1) return;
    //             visit[y-1] = false;
    //         }
    //     }
    //     return;
    // };

    // FOR(i, 1, n+1){
    //     visit[i-1] = true;
    //     dfs(dfs, i, -1);
    //     if(ans!=-1) break;
    //     visit[i-1] = false;
    // }

    // if(ans!=-1){
    //     cout << "YES" << endl;
    //     // cout << ans << endl;
    //     // print(visit);
    //     // print(parent);

    //     int x = ans;
    //     while(true){
    //         cout << x << ' ';
    //         // for(int y: G[x-1]){
    //         //     if(visit[y-1]){
    //         //         x = y;
    //         //         break;
    //         //     }
    //         // }
    //         x = parent[x-1];
    //         if(x==ans) break;
    //     }
    // }else{
    //     cout << "NO" << endl;
    // }


    // int ans = -1;
    // vector < int > last(n, -1);

    // auto dfs = [&](auto&& self, int x, int p, int start) -> void {
    //     if(ans!=-1) return;
    //     else if(x==start and p!=-1){
    //         ans = true;
    //         return;
    //     }
    //     for(int y: G[x-1]){
    //         if(y==p) continue;
    //         last[x-1] = y;
    //         self(self, y, x, start);
    //         if(ans!=-1) return;
    //     }
    //     return;
    // };

    // FOR(i, 1, n+1){
    //     dfs(dfs, i, -1, i);
    //     if(ans!=-1){
    //         cout << "YES" << endl;

    //         int x = i;
    //         while(true){
    //             cout << x << ' ';
    //             x = last[x-1];
    //             if(x==i) break;
    //         }

    //         break;
    //     }
    // }

    // if(ans==-1){
    //     cout << "NO" << endl;
    // }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
