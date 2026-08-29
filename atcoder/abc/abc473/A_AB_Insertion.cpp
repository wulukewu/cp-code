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
    vector<int> sum, mn;
    SegTree(int _n) {
        n = _n;
        sum.resize(n * 4 + 5);
        mn.resize(n * 4 + 5, 0);
    }
    void push_up(int node) {
        sum[node] = sum[2 * node] + sum[2 * node + 1]; // add
        mn[node] = min(mn[2*node], sum[2*node]+mn[2*node+1]);
    }
    void _build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            sum[node] = arr[start];
            mn[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        _build(2 * node, start, mid, arr);
        _build(2 * node + 1, mid + 1, end, arr);
        push_up(node);
    }
    void _update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            sum[node] = val;
            mn[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) _update(2 * node, start, mid, idx, val);
        else _update(2 * node + 1, mid + 1, end, idx, val);
        push_up(node);
    }
    pair<int, int>merge(pair<int, int>L, pair<int, int>R){
        return {
            L.F+R.F, min(L.S, L.F+R.S)
        };
    }
    pair<int, int> _query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) return {sum[node], mn[node]};
        int mid = (start + end) / 2;
        if (r <= mid) return _query(2 * node, start, mid, l, r);
        if (l > mid)  return _query(2 * node + 1, mid + 1, end, l, r);
        auto L = _query(2 * node, start, mid, l, r);
        auto R = _query(2 * node + 1, mid + 1, end, l, r);
        return merge(L, R);
    }
    void init(const vector<int>& arr) {
        _build(1, 1, n, arr);
    }
    void modify(int idx, int val) {
        _update(1, 1, n, idx, val);
    }
    pair<int, int> query(int l, int r) {
        return _query(1, 1, n, l, r);
    }
};

void solve(){
    int n;
    string s;
    cin >> n >> s;

    vector<int>arr(n+1);
    FOR(i, 1, n+1){
        arr[i] = s[i-1]=='A' ? 1 : -1;
    }

    SegTree seg(n);
    seg.init(arr);

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type==1){
            int i;
            char c;
            cin >> i >> c;

            s[i-1] = c;
            seg.modify(i, c=='A' ? 1 : -1);
        }else{
            int l, r;
            cin >> l >> r;
            auto res = seg.query(l, r);
            cout << (res.S>=0 ? "Yes" : "No") << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
