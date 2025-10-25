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
    int u, v;
    FOR(i, 0, m){
        cin >> u >> v;
        u--; v--;
        G[u].PB(v);
        G[v].PB(u);
    }

    string s;
    cin >> s;

    vector < int > arr(n, INT_MAX);
    vector < bool > vis(n, false);

    auto dfs = [&](auto&& self, int x) -> int {
        cout << x << endl;
        if(s[x]=='S'){
            arr[x] = 0;
            return 0;
        }
        if(arr[x]!=INT_MAX){
            return arr[x];
        }

        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for(int& i: G[x]){
            if(!vis[i]){
                vis[i] = true;
                int t = self(self, i) + 1;
                vis[i] = false;

                if(t<=m1){
                    m2 = m1;
                    m1 = t;
                }else if(t<=m2){
                    m2 = t;
                }
            }
        }

        cout << x << ' ' << m1 << ' ' << m2 << endl;
        int res = m1 + m2;
        arr[x] = res;
        return res;
    };

    FOR(i, 0, n){
        if(s[i]=='S'){
            arr[i] = 0;
        }else if(arr[i]==INT_MAX){
            vis[i] = true;
            dfs(dfs, i);
            vis[i] = false;
        }
    }

    print(arr);

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
