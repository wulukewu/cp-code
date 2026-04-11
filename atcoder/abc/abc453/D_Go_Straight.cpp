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
    int h, w;
    cin >> h >> w;
    vector<string>arr(h);
    FOR(i, 0, h) cin >> arr[i];

    int sx, sy, gx, gy;
    FOR(i, 0, h){
        FOR(j, 0, w){
            if(arr[i][j]=='S'){
                sx = i;
                sy = j;
            }else if(arr[i][j]=='G'){
                gx = i;
                gy = j;
            }
        }
    }

    int offs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    char dic[4] = {'D', 'U', 'R', 'L'};
    vector<vector<vector<bool>>>visit(h, vector<vector<bool>>(w, vector<bool>(5, false)));
    bool ans = false;
    string ansp = "";
    // queue<int>path;
    vector<int>path;
    auto dfs = [&](auto&& self, int x, int y, int dir) -> void {
        if(ans) return;
        if(x==gx and y==gy){
            ans = true;
            // stack<int>p2;
            // while(!path.empty()){
            //     int a = path.front();
            //     ansp += dic[a];
            //     p2.push(a);
            //     path.pop_back();
            // }
            // while(!p2.empty()){
            //     path.push(p2.top());
            //     p2.pop();
            // }
            for(int i: path){
                ansp += dic[i];
            }
            return;
        }

        // vector<pair<int, pair<int, int>>>mv;
        // if(dir==0){
        //     FOR(k, 0, 4){
        //         mv.PB({k, {offs[k][0], offs[k][1]}});
        //     }
        // }else if(dir>0){
        //     mv.PB({dir-1, {offs[dir-1][0], offs[dir-1][1]}});
        // }else{
        //     FOR(k, 0, 4){
        //         if(-dir-1!=k){
        //             mv.PB({-dir-1, {offs[k][0], offs[k][1]}});
        //         }
        //     }
        // }

        FOR(k, 0, 4){
        // for(auto k: mv){
            // int d = k.F;
            // int r = x + k.S.F;
            // int c = y + k.S.S;
            int r = x + offs[k][0];
            int c = y + offs[k][1];
            if(!(0<=r and r<h and 0<=c and c<w)) continue;
            if(visit[r][c][k]) continue;
            if(arr[r][c]=='#') continue;
            else if(arr[x][y]=='o'){
                if(k==dir){
                    visit[r][c][k] = true;
                    path.PB(k);
                    self(self, r, c, k);
                    // visit[r][c][k] = false;
                    path.pop_back();
                }
            }else if(arr[x][y]=='x'){
                if(k!=dir){
                    visit[r][c][k] = true;
                    path.PB(k);
                    self(self, r, c, k);
                    // visit[r][c][k] = false;
                    path.pop_back();
                }
            }else{
                visit[r][c][k] = true;
                path.PB(k);
                self(self, r, c, k);
                // visit[r][c][k] = false;
                path.pop_back();
            }
        }
    };

    visit[sx][sy][4] = true;
    dfs(dfs, sx, sy, -1);
    if(ans){
        cout << "Yes" << endl;
        cout << ansp << endl;
    }else{
        cout << "No" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
