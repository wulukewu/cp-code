// ==================================================
// Problem   : ABC427_D - The Simple Game
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc427/tasks/abc427_d
// ==================================================

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
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector < vector < int > > G(n);
    int u, v;
    FOR(i, 0, m){
        cin >> u >> v;
        G[u-1].PB(v-1);
    }

    // FOR(i, 0, n){
    //     cout << i << ": ";
    //     print(G[i]);
    // }

    vector < vector < int > > arr(n, vector < int > (k+1, -1));

    auto dfs = [&](auto&& self, int x, int y) -> bool {
        // cout << x << ' ' << y << endl;
        if(y==0){
            return s[x]=='A';
        }

        if(arr[x][y]!=-1){
            return arr[x][y];
        }

        for(int i: G[x]){
            bool check = true;
            for(int j: G[i]){
                if(!self(self, j, y-1)){
                    check = false;
                    break;
                }
            }
            if(check){
                arr[x][y] = 1;
                return true;
            }
        }
        arr[x][y] = 0;
        return false;
    };

    bool ans = dfs(dfs, 0, k);
    if(ans){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
    }

    // cout << '-' << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
