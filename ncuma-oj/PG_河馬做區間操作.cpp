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

template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        // init(std::vector(n_, v_));
        init(std::vector<Info>(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        // info.assign(4 << std::__lg(n), Info());
        info.assign(4 * n + 5, Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = {init_[l], init_[l]};
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    // void modify(int p, int l, int r, int x, const Info &v) {
    //     if (r - l == 1) {
    //         info[p] = v;
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     if (x < m) {
    //         modify(2 * p, l, m, x, v);
    //     } else {
    //         modify(2 * p + 1, m, r, x, v);
    //     }
    //     pull(p);
    // }
    // void modify(int p, const Info &v) {
    //     modify(1, 0, n, p, v);
    // }
    
    // void rangeAdd(int p, int l, int r, int x, int y, int v) {
    //     if (l >= y or r <= x) {
    //         return;
    //     }
    //     if (l >= x and r <= y) {
    //         info[p].x += v * (r - l);
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     rangeAdd(2 * p, l, m, x, y, v);
    //     rangeAdd(2 * p + 1, m, r, x, y, v);
    //     pull(p);
    // }
    
    // void rangeAdd(int x, int y, int v) {
    //     rangeAdd(1, 0, n, x, y, v);
    // }
    
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }

    void rangeSqrt(int p, int l, int r, int x, int y){
        if(l>=y or r<=x) return;

        if(info[p].y<=1) return;

        if(r-l==1){
            info[p].x = sqrt(info[p].x);
            info[p].y = info[p].x;
            return;
        }

        int m = (l+r)/2;
        rangeSqrt(2*p, l, m, x, y);
        rangeSqrt(2*p+1, m, r, x, y);
        pull(p);
    }
    void rangeSqrt(int l, int r){
        rangeSqrt(1, 0, n, l, r);
    }
    
    // // auto pred = [&](const Info &info) { return info.x > 1;};
    // template<class F>
    // int findFirst(int p, int l, int r, int x, int y, F &&pred) {
    //     if (l >= y || r <= x) {
    //         return -1;
    //     }
    //     if (l >= x && r <= y && !pred(info[p])) {
    //         return -1;
    //     }
    //     if (r - l == 1) {
    //         return l;
    //     }
    //     int m = (l + r) / 2;
    //     int res = findFirst(2 * p, l, m, x, y, pred);
    //     if (res == -1) {
    //         res = findFirst(2 * p + 1, m, r, x, y, pred);
    //     }
    //     return res;
    // }
    // template<class F>
    // int findFirst(int l, int r, F &&pred) {
    //     return findFirst(1, 0, n, l, r, pred);
    // }
    // template<class F>
    // int findLast(int p, int l, int r, int x, int y, F &&pred) {
    //     if (l >= y || r <= x) {
    //         return -1;
    //     }
    //     if (l >= x && r <= y && !pred(info[p])) {
    //         return -1;
    //     }
    //     if (r - l == 1) {
    //         return l;
    //     }
    //     int m = (l + r) / 2;
    //     int res = findLast(2 * p + 1, m, r, x, y, pred);
    //     if (res == -1) {
    //         res = findLast(2 * p, l, m, x, y, pred);
    //     }
    //     return res;
    // }
    // template<class F>
    // int findLast(int l, int r, F &&pred) {
    //     return findLast(1, 0, n, l, r, pred);
    // }
};
 
struct Info {
    int x = 0; // sum
    int y = 0; // max value
};
 
Info operator+(const Info &a, const Info &b) {
    return {a.x + b.x, max(a.y, b.y)};
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];

    SegmentTree < Info > st(arr);

    int x, l, r;
    FOR(i, 0, q){
        cin >> x >> l >> r;
        if(x==0){
            cout << st.rangeQuery(l-1, r).x << endl;
        }else{
            st.rangeSqrt(l-1, r);
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
