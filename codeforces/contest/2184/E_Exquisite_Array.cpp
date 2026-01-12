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
    int n;
    cin >> n;

    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];

    vector<vector<int>>brr(n);
    FOR(i, 0, n-1){
        int d = abs(arr[i]-arr[i+1]);
        brr[d].PB(i);
    }

    vector<int>boss(n);
    vector<int>sz(n, 1);
    FOR(i, 0, n) boss[i] = i;

    auto find_root = [&](int x, auto&& self) -> int {
        if(boss[x]==x) return x;
        int root = self(boss[x], self);
        boss[x] = root;
        return root;
    };

    auto connect = [&](int x, int y) -> void {
        int root_x = find_root(x, find_root);
        int root_y = find_root(y, find_root);
        if(root_x != root_y){
            boss[root_x] = root_y;
            sz[root_y] += sz[root_x];
        }
    };

    auto cal = [](int x) -> int {
        return x * (x-1) / 2;
    };

    int res = 0;
    vector<int>ans(n);
    for(int k=n-1; k>=1; k--){
        for(auto i: brr[k]){
            int u = i, v = i+1;
            u = find_root(u, find_root);
            v = find_root(v, find_root);
            if(u != v){
                res -= cal(sz[u]);
                res -= cal(sz[v]);
                connect(u, v);
                int root = find_root(u, find_root);
                res += cal(sz[root]);
            }
        }
        ans[k] = res;
    }

    FOR(i, 1, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
