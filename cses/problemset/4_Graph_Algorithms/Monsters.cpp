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
    int n, m;
    cin >> n >> m;
    int sr=-1, sc=-1;
    vector<pair<int, int>>mon;
    vector<string>arr(n);
    FOR(i, 0, n){
        cin >> arr[i];
        FOR(j, 0, m){
            if(arr[i][j]=='A'){
                sr = i, sc = j;
            }
            if(arr[i][j]=='M'){
                mon.PB({i, j});
            }
        }
    }

    const int INF = 1e6+10;
    const int offs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    const char offs_dir[4] = {'D', 'U', 'R', 'L'};
    vector<vector<int>>v(n, vector<int>(m, INF));
    vector<vector<bool>>vis_mon(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>>q_mon;
    for(auto [mr, mc]: mon){
        q_mon.push({{mr, mc}, 0});
        vis_mon[mr][mc] = true;
    }
    while(!q_mon.empty()){
        auto [rc, t] = q_mon.front();
        auto [r, c] = rc;
        q_mon.pop();
        // v[r][c] = min(v[r][c], t);
        if(t<v[r][c]){
            v[r][c] = t;
        }else{
            continue;
        }
        FOR(k, 0, 4){
            int x = r + offs[k][0];
            int y = c + offs[k][1];
            if(!(0<=x and x<n and 0<=y and y<m)) continue;
            if(arr[x][y]=='#') continue;
            if(vis_mon[x][y]) continue;
            vis_mon[x][y] = true;
            q_mon.push({{x, y}, t+1});
        }
    }
    // FOR(i, 0, n) print(v[i]);
    
    vector<vector<bool>>vis(n, vector<bool>(m, false));
    vector<vector<char>>from(n, vector<char>(m, '.'));
    queue<pair<pair<int, int>, int>>q;
    q.push({{sr, sc}, 0});
    while(!q.empty()){
        auto [rc, t] = q.front();
        auto [r, c] = rc;
        q.pop();
        if(r==0 or r==n-1 or c==0 or c==m-1){
            // cout << r << ' ' << c << endl;
            // FOR(i, 0, n) print(from[i]);
            cout << "YES" << endl;
            vector<char>ans;
            while(r!=sr or c!=sc){
                char dir = from[r][c];
                ans.PB(dir);
                if(dir=='D') r--;
                else if(dir=='U') r++;
                else if(dir=='R') c--;
                else c++;
            }
            reverse(ALL(ans));
            // print(ans);
            cout << ans.size() << endl;
            for(char c: ans) cout << c;
            return;
        }
        FOR(k, 0, 4){
            int x = r + offs[k][0];
            int y = c + offs[k][1];
            if(!(0<=x and x<n and 0<=y and y<m)) continue;
            if(arr[x][y]=='#') continue;
            if(t+1>=v[x][y]) continue;
            if(vis[x][y]) continue;
            vis[x][y] = true;
            q.push({{x, y}, t+1});
            from[x][y] = offs_dir[k];
        }
    }
    cout << "NO" << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
