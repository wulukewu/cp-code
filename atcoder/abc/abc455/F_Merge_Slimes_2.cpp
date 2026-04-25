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
const ll MOD = 998244353;
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

struct Node{
    int sum1 = 0;
    int sum2 = 0;
    int len = 0;
};
class SegTree {
public:
    int n;
    vector<Node>tree;
    vector<int>lazy;
    SegTree(int _n) {
        n = _n;
        tree.resize(n * 4 + 5);
        lazy.resize(n * 4 + 5, 0);
    }
    void apply(int node, int val){
        val %= MOD;
        int len = tree[node].len;
        int val2 = (val*val) % MOD;
        // tree[node].sum2 += 2*val*tree[node].sum1 + len*val2;
        // tree[node].sum2 %= MOD;
        tree[node].sum2 = (tree[node].sum2 + 2 * val % MOD * tree[node].sum1 % MOD + len * val2 % MOD) % MOD;
        tree[node].sum1 += len*val;
        tree[node].sum1 %= MOD;
        lazy[node] += val;
        lazy[node] %= MOD;
    }
    void push_up(int node) {
        tree[node].sum1 = tree[2 * node].sum1 + tree[2 * node + 1].sum1;
        tree[node].sum1 %= MOD;
        tree[node].sum2 = tree[2 * node].sum2 + tree[2 * node + 1].sum2;
        tree[node].sum2 %= MOD;
    }
    void push_down(int node, int start, int end) {
        if (lazy[node] != 0) {
            apply(2*node, lazy[node]);
            apply(2*node+1, lazy[node]);
            lazy[node] = 0;
        }
    }
    void _build(int node, int start, int end) {
        tree[node].len = end-start+1;
        tree[node].sum1 = 0;
        tree[node].sum2 = 0;
        if (start == end) return;

        int mid = (start + end) / 2;
        _build(2 * node, start, mid);
        _build(2 * node + 1, mid + 1, end);
        push_up(node);
    }
    void _update(int node, int start, int end, int l, int r, int val) {
        if (l <= start && end <= r) {
            apply(node, val);
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        if (l <= mid) _update(2 * node, start, mid, l, r, val);
        if (r > mid)  _update(2 * node + 1, mid + 1, end, l, r, val);
        push_up(node);
    }
    Node _query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) return tree[node];
        push_down(node, start, end);
        int mid = (start + end) / 2;

        if(r<=mid) return _query(2*node, start, mid, l, r);
        if(l>mid) return _query(2*node+1, mid+1, end, l, r);
        
        Node left = _query(2*node, start, mid, l, r);
        Node right =  _query(2*node+1, mid+1, end, l, r);
        Node res;
        res.len = left.len + right.len;
        res.sum1 = left.sum1 + right.sum1;
        res.sum1 %= MOD;
        res.sum2 = left.sum2 + right.sum2;
        res.sum2 %= MOD;

        return res;
    }
    void init() {
        _build(1, 1, n);
    }
    void modify(int l, int r, int val) {
        _update(1, 1, n, l, r, val);
    }
    void modify(int idx, int val) {
        _update(1, 1, n, idx, idx, val);
    }
    Node query(int l, int r) {
        return _query(1, 1, n, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    SegTree seg(n);
    seg.init();

    int inv2 = POW(2, MOD-2);

    FOR(i, 0, q){
        int l, r, a;
        cin >> l >> r >> a;
        seg.modify(l, r, a);

        Node res = seg.query(l, r);
        int sum1 = res.sum1;
        int sum2 = res.sum2;

        int sum1_sq = (sum1*sum1) % MOD;
        int ans = (sum1_sq-sum2 + MOD) % MOD;
        ans = (ans*inv2) % MOD;

        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
