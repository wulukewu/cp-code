#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
// #define endl '\n'
#define endl endl << flush
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

vector<int> query(int k){
    cout << "? " << k << endl;
    int q;
    cin >> q;
    if(q==0 or q==-1) return {};
    vector<int> path(q);
    FOR(i, 0, q) cin >> path[i];
    return path;
}

void solve(){
    int n;
    cin >> n;

    int m = 0;
    vector<pair<int, int>>ans;
    int cur = 1;
    // int l = 0, r = 2e9;
    while(true){
        vector<int> path = query(cur);

        if(path.empty()) break;
        if(path.size()<2){
            cur++;
            continue;
        }

        int u = path[0];
        int v = path[1];
        ans.PB({u, v});

        int l = cur + 1;
        int r = (1LL << 30);
        int last = cur;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<int> pmid = query(mid);

            bool same = false;
            if(pmid.size()>=2 and pmid[0]==u and pmid[1]==v){
                same = true;
            }
            if(same){
                last = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        cur = last + 1;

        // int m = l + (r-l)/2;
        // cout << "? " << m << endl;
        // int q;
        // cin >> q;
        // if(q==0){
        //     r = m - 1;
        // }else{
        //     l = m + 1;
        // }

        // vector<int>arr(q);
        // FOR(i, 0, q) cin >> arr[i];
        // FOR(i, 0, q-1){
        //     if(G[arr[i]].find(arr[i+1])==G[arr[i]].end()){
        //         G[i].insert(arr[i+1]);
        //     }
        // }

        // string ss;
        // getline(cin, ss);
        // stringstream s(ss);
        // int x;
        // vector<int>tmp;
        // while(s>>x){
        //     tmp.PB(x);
        // }
        
        // int sz = tmp.size();
        // FOR(i, 0, sz-1){
        //     if(G[tmp[i]].find(tmp[i+1])==G[tmp[i]].end()){
        //         G[i].insert(tmp[i+1]);
        //     }
        // }
    }

    // vector<pair<int, int>>ans;
    // FOR(i, 0, n){
    //     for(int j: G[i]){
    //         ans.PB({i+1, j});
    //     }
    // }
    cout << "! " << ans.size() << endl;
    for(auto i: ans){
        cout << i.F << ' ' << i.S << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
