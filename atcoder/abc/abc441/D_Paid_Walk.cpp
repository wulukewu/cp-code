// ==================================================
// Problem   : ABC441_D - Paid Walk
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc441/tasks/abc441_d
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
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
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

void solve(){
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;

    vector<vector<pair<int, int>>>G(n);
    FOR(i, 0, m){
        int u, v, c;
        cin >> u >> v >> c;
        G[u-1].PB({v-1, c});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    set<int>ans;
    while(!q.empty()){
        auto fr = q.front();
        int x = fr.F;
        int y = fr.S.F;
        int z = fr.S.S;
        q.pop();

        if(z<l){
            for(auto i: G[x]){
                q.push({i.F, {y+i.S, z+1}});
            }
        }else if(z==l and s<=y and y<=t){
            ans.insert(x+1);
        }
    }

    for(int i: ans){
        cout << i << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
