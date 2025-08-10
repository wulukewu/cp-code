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
    int n;
    cin >> n;

    vector < int > G(n+1);
    FOR(i, 1, n+1){
        cin >> G[i];
    }

    vector < int > state(n+1, 0);
    vector < bool > mobster(n+1, false);
    int ans = 0;

    auto dfs = [&](auto&& self, int u) -> void {
        state[u] = 1;
        int v = G[u];
        if(state[v]==0){
            self(self, v);
        }
        else if(state[v]==1){
            ans++;
            while(true){
                state[v] = 2;
                mobster[v] = false;
                if(v==u) break;
                v = G[v];
            }
            return;
        }

        if(state[u]==2) return;

        if(mobster[v]){
            mobster[u] = false;
        }else{
            mobster[u] = true;
            ans++;
        }

        state[u] = 2;
    };

    FOR(i, 1, n+1){
        if(state[i]==0) dfs(dfs, i);
    }

    // print(state);
    // print(mobster);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
