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

struct Node {
    int sum, pre;
};
Node seg[800005];
void build (int id, int l, int r, vector<int>&a){
    if(l==r){
        seg[id].sum = a[l];
        seg[id].pre = max(0ll, a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid, a);
    build(id*2+1, mid+1, r, a);

    Node L = seg[id*2];
    Node R = seg[id*2+1];
    seg[id].sum = L.sum + R.sum;
    seg[id].pre = max(L.pre, L.sum + R.pre);
}
void update (int id, int l, int r, int k, int u){
    if(l==r){
        seg[id].sum = u;
        seg[id].pre = max(0ll, u);
        return;
    }
    int mid = (l+r)/2;
    if(k<=mid){
        update(id*2, l, mid, k, u);
    }else{
        update(id*2+1, mid+1, r, k, u);
    }

    Node L = seg[id*2];
    Node R = seg[id*2+1];
    seg[id].sum = L.sum + R.sum;
    seg[id].pre = max(L.pre, L.sum + R.pre);
}
Node query (int id, int l, int r, int ql, int qr){
    if(ql<=l and r<=qr){
        return seg[id];
    }
    int mid = (l+r)/2;
    if(qr<=mid){
        return query(id*2, l, mid, ql, qr);
    }else if(ql>mid){
        return query(id*2+1, mid+1, r, ql, qr);
    }else{
        Node L = query(id*2, l, mid, ql, qr);
        Node R = query(id*2+1, mid+1, r, ql, qr);
        Node res;
        res.sum = L.sum + R.sum;
        res.pre = max(L.pre, L.sum + R.pre);
        return res;
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int>a(n+1);
    FOR(i, 1, n+1) cin >> a[i];
    build(1, 1, n, a);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        }else{
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b).pre << endl;
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
