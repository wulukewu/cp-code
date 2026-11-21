/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc482_e // Diameter Endpoint Colors
 https://atcoder.jp/contests/abc482/tasks/abc482_e

 AC // C++23 (GCC 15.2.0) // 135 ms // 475.0 pt
 #80523690 // 2026-10-31 21:18:19 +0800
 https://atcoder.jp/contests/abc482/submissions/80523690

 cp-code:submission-metadata
*/

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
template<typename T>
class BIT{
public:
    vector<T>bit;
    int size;
    BIT(int s){size=s;bit=vector<T>(size,0);}
    int lb(int x){return x&(-x);}
    void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
    T sum(int x){T res=0;for(int i=x;i>0;i-=lb(i))res+=bit[i];return res;}
};
class SegTree {
public:
    int n;
    vector<int> tree, lazy;
    SegTree(int _n) {
        n = _n;
        tree.resize(n * 4 + 5);
        lazy.resize(n * 4 + 5, 0);
    }
    void push_up(int node) {
        tree[node] = tree[2 * node] + tree[2 * node + 1]; // add
        // tree[node] = min(tree[2*node], tree[2*node+1]); // min
    }
    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = (start + end) / 2;
            lazy[2 * node] += lazy[node];
            tree[2 * node] += lazy[node] * (mid - start + 1); // add
            // tree[2*node] += lazy[node]; // min
            lazy[2 * node + 1] += lazy[node];
            tree[2 * node + 1] += lazy[node] * (end - mid); // add
            // tree[2*node+1] += lazy[node]; // min
            lazy[node] = 0;
        }
    }
    void _build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        _build(2 * node, start, mid, arr);
        _build(2 * node + 1, mid + 1, end, arr);
        push_up(node);
    }
    void _update(int node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            tree[node] += val * (end - start + 1); // add
            // tree[node] += val; // min
            lazy[node] += val;
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        if (l <= mid) _update(2 * node, start, mid, l, r, val);
        if (r > mid)  _update(2 * node + 1, mid + 1, end, l, r, val);
        push_up(node);
    }
    int _query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) return tree[node];
        push_down(node, start, end);
        int mid = (start + end) / 2;
        int res = 0; // add
        // int res = 1e18; // min
        if (l <= mid) res += _query(2 * node, start, mid, l, r); // add
        // if (l <= mid) res = min(res, _query(2 * node, start, mid, l, r)); // min
        if (r > mid)  res += _query(2 * node + 1, mid + 1, end, l, r); // add
        // if (r > mid)  res = min(res, _query(2 * node + 1, mid + 1, end, l, r)); // min
        return res;
    }
    void init(const vector<int>& arr) {
        _build(1, 1, n, arr);
    }
    void modify(int l, int r, int val) {
        _update(1, 1, n, l, r, val);
    }
    void modify(int idx, int val) {
        _update(1, 1, n, idx, idx, val);
    }
    int query(int l, int r) {
        return _query(1, 1, n, l, r);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    FOR(i, 0, n-1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].PB(v);
        g[v].PB(u);
    }
    vector<int>c(n);
    FOR(i, 0, n) cin >> c[i];

    vector<int>dist(n, -1);
    vector<int>par(n, -1);
    auto bfs = [&](int s) -> int {
        fill(ALL(dist), -1);
        fill(ALL(par), -1);

        queue<int>q;
        q.push(s);
        dist[s] = 0;

        int far = s;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(dist[u]>dist[far]) far = u;
            for(int v: g[u]){
                if(dist[v]!=-1) continue;
                dist[v] = dist[u]+1;
                par[v] = u;
                q.push(v);
            }
        }
        return far;
    };

    int a = bfs(0);
    int b = bfs(a);
    int d = dist[b];
    vector<int>path;
    for(int u=b; u!=-1; u=par[u]){
        path.PB(u);
    }
    // print(path);

    auto dfs = [&](int s, int p, int dep, int tar) {
        map<int, int>mp;
        stack<tuple<int, int, int>>st;
        st.push({s, p, dep});
        while(!st.empty()){
            auto [u, fa, depth] = st.top();
            st.pop();

            if(depth==tar){
                mp[c[u]]++;
                continue;
            }
            for(int v: g[u]){
                if(v==fa) continue;
                st.push({v, u, depth+1});
            }
        }
        return mp;
    };

    int ans = 0;
    if(d%2==0){
        int o = path[d/2];
        map<int, int>cnt;
        for(int v: g[o]){
            auto tmp = dfs(v, o, 1, d/2);
            for(auto [col, num]: tmp){
                ans += num * cnt[col];
            }
            for(auto [col, num]: tmp){
                cnt[col] += num;
            }
        }
    }else{
        int u = path[d/2];
        int v = path[d/2+1];
        auto l = dfs(u, v, 0, d/2);
        auto r = dfs(v, u, 0, d/2);
        for(auto [col, num]: l){
            ans += num * r[col];
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
