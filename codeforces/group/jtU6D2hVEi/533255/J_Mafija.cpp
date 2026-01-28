// ==================================================
// Problem   : jtU6D2hVEiJ - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/J
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
    int n;
    cin >> n;

    vector < int > G(n+1);
    FOR(i, 1, n+1){
        cin >> G[i];
    }

    vector < vector < int > > rev(n+1);
    vector < int > indeg(n+1, 0);
    FOR(i, 1, n+1){
        indeg[G[i]]++;
        rev[G[i]].PB(i);
    }

    queue < int > q;
    FOR(i, 1, n+1){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector < bool > cycle(n+1, true);
    vector < int > topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        cycle[u] = false;
        topo.PB(u);
        int v = G[u];
        indeg[v]--;
        if(indeg[v]==0){
            q.push(v);
        }
    }

    vector < int > dp0(n+1, 0);
    vector < int > dp1(n+1, 0);
    for(int u: topo){
        int c0 = 0;
        int c1 = 1;
        for(int c: rev[u]){
            if(cycle[c]) continue;
            c0 += max(dp0[c], dp1[c]);
            c1 += dp0[c];
        }
        dp0[u] = c0;
        dp1[u] = c1;
    }

    int ans = 0;
    vector < bool > visit(n+1, false);
    FOR(i, 1, n+1){
        if(!cycle[i] or visit[i]) continue;
        vector < int > cyc;
        int u = i;
        while(!visit[u]){
            visit[u] = 1;
            cyc.PB(u);
            u = G[u];
        }
        int k = cyc.size();
        // cout << "k: " << k << endl;

        vector < int > val0(k, 0);
        vector < int > val1(k, 0);
        FOR(j, 0, k){
            int idx = cyc[j];
            int sum0 = 0;
            int sum1 = 1;
            for(int c: rev[idx]){
                if(cycle[c]) continue;
                sum0 += max(dp0[c], dp1[c]);
                sum1 += dp0[c];
            }
            val0[j] = sum0;
            val1[j] = sum1;
        }
        // cout << "val0 ";
        // print(val0);
        // cout << "val1 ";
        // print(val1);

        int base = 0;
        vector < int > gain(k);
        FOR(j, 0, k){
            base += val0[j];
            gain[j] = val1[j] - val0[j];
        }
        // cout << "base: " << base << endl;
        // cout << "gain: ";
        // print(gain);

        auto sl = [&](int l, int r) -> int {
            if(l>r) return 0;
            int pn = 0;
            int ps = -4e18;
            FOR(j, l, r+1){
                int cs = pn + gain[j];
                int cn = max(pn, ps);
                pn = cn;
                ps = cs;
            }
            return max(pn, ps);
        };

        int ans1 = sl(1, k-1);
        int ans2 = gain[0] + sl(2, k-2);
        int best = max(ans1, ans2);
        ans += base + best;
    }

    cout << ans << endl;
}

// void solve() {
//     int n;
//     cin >> n;

//     vector < int > G(n+1);
//     FOR(i, 1, n+1){
//         cin >> G[i];
//     }

//     vector < int > state(n+1, 0);
//     vector < bool > mobster(n+1, false);
//     int ans = 0;

//     auto dfs = [&](auto&& self, int u) -> void {
//         state[u] = 1;
//         int v = G[u];
//         if(state[v]==0){
//             self(self, v);
//         }
//         else if(state[v]==1){
//             ans++;
//             cout << v << endl;
//             while(true){
//                 state[v] = 2;
//                 mobster[v] = false;
//                 if(v==u) break;
//                 v = G[v];
//             }
//             return;
//         }

//         if(state[u]==2) return;

//         if(mobster[v]){
//             mobster[u] = false;
//         }else{
//             mobster[u] = true;
//             ans++;
//             cout << u << endl;
//         }

//         state[u] = 2;
//     };

//     FOR(i, 1, n+1){
//         if(state[i]==0) dfs(dfs, i);
//     }

//     print(state);
//     print(mobster);

//     cout << ans << endl;
// }

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
