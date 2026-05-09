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

    vector<vector<pair<int, int>>>left(n);
    vector<vector<pair<int, int>>>right(n);
    FOR(i, 0, m){
        int l, r;
        cin >> l >> r;
        l--; r--;
        left[l].PB({r, i});
        right[r].PB({l, i});
    }

    FOR(i, 0, n){
        sort(ALL(left[i]));
        sort(ALL(right[i]));
    }

    vector<vector<pair<int, int>>>min2(n+1);
    for(int i=n-1; i>=0; i--){
        vector<pair<int, int>>arr = min2[i+1];
        for(auto j: left[i]){
            arr.PB(j);
        }
        sort(ALL(arr));

        if(arr.size()>0) min2[i].PB(arr[0]);
        if(arr.size()>1) min2[i].PB(arr[1]);
    }

    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        s--; t--;

        vector<pair<int, int>>xrr;
        auto itx = upper_bound(ALL(left[s]), make_pair(t, 1e9));
        if(itx != left[s].begin()){
            auto it = itx;
            it--;
            xrr.PB(*it);
            if(it != left[s].begin()){
                it--;
                xrr.PB(*it);
            }
        }
        vector<pair<int, int>>yrr;
        auto ity = lower_bound(ALL(right[t]), make_pair(s, -1));
        if(ity != right[t].end()){
            auto it = ity;
            yrr.PB(*it);
            it++;
            if(it != right[t].end()){
                yrr.PB(*it);
            }
        }

        int ans = false;
        for(auto x: xrr){
            for(auto y: yrr){
                if(y.F<=x.F+1 and x.S!=y.S){
                    ans = true;
                }
            }
        }
        if(!ans){
            int id = -1;
            for(auto x: xrr){
                if(x.F==t){
                    id = x.S;
                    break;
                }
            }

            if(id!=-1){
                for(auto p: min2[s]){
                    if(p.F<=t and p.S!=id){
                        ans = true;
                        break;
                    }
                }
            }
        }

        if(ans){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    // int n, m;
    // cin >> n >> m;
    // vector<set<pair<int, int>>>v(n);
    // FOR(i, 0, m){
    //     int l, r;
    //     cin >> l >> r;
    //     l--; r--;
    //     v[l].insert({r, i});
    //     v[r].insert({l, i});
    // }

    // int q;
    // cin >> q;
    // while(q--){
    //     int s, t;
    //     cin >> s >> t;
    //     s--; t--;

    //     bool det = false;
    //     // if(v[s].empty() or v[t].empty()) continue;
    //     for(auto i: v[s]){
    //         if(s>i.F) continue;
    //         for(auto j: v[t]){
    //             if(t<j.F) continue;
    //             if(i.F<=t and j.F>=s and i.S!=j.S){
    //                 // cout << s << ' ' << i.F << ' ' << j.F << ' ' << t << ' ' << i.F << ' ' << i.S << endl;
    //                 det = true;
    //                 // break;
    //             }
    //         }
    //     }
    //     if(det){
    //         cout << "Yes" << endl;
    //     }else{
    //         cout << "No" << endl;
    //     }
    // }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
