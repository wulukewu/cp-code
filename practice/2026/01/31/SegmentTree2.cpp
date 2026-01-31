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
class fenwick{
public:
    vector<T>bit;
    int size;
    fenwick(int s){size=s;bit=vector<T>(size,0);}
    int lb(int x){return x&(-x);}
    void up(int x,T y){for(int i=x;i<size;i+=lb(i))bit[i]+=y;}
    T sum(int x){T res=0;for(int i=x;i>0;i-=lb(i))res+=bit[i];return res;}
};

const int MAXN = 2e5+5;
int arr[MAXN];
int tree[4*MAXN];
int lazy[4*MAXN];
void push_up(int node){
    tree[node] = tree[2*node] + tree[2*node+1];
}
void push_down(int node, int start, int end){
    if(lazy[node]!=0){
        int mid = (start + end) / 2;

        lazy[2*node] += lazy[node];
        tree[2*node] += lazy[node] * (mid-start+1);

        lazy[2*node+1] += lazy[node];
        tree[2*node+1] += lazy[node] * (end-mid);

        lazy[node] = 0;
    }
}
void build(int node, int start, int end){
    lazy[node] = 0;
    if(start==end){
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    push_up(node);
}
// void update(int node, int start, int end, int idx, int val){
//     if(start==end){
//         arr[idx] = val;
//         tree[node] = val;
//         return;
//     }

//     int mid = (start + end) / 2;
//     if(idx<=mid){
//         update(2*node, start, mid, idx, val);
//     }else{
//         update(2*node+1, mid+1, end, idx, val);
//     }

//     push_up(node);
// }
void update(int node, int start, int end, int l, int r, int val){
    if(l<=start and end<=r){
        tree[node] += val * (end-start+1);
        lazy[node] += val;
        return;
    }

    push_down(node, start, end);

    int mid = (start + end) / 2;
    if(l<=mid){
        update(2*node, start, mid, l, r, val);
    }
    if(r>mid){
        update(2*node+1, mid+1, end, l, r, val);
    }

    push_up(node);
}
int query(int node, int start, int end, int l, int r){
    if(l<=start and end<=r){
        return tree[node];
    }

    push_down(node, start, end);

    int mid = (start + end) / 2;
    int sum = 0;
    if(l<=mid){
        sum += query(2*node, start, mid, l, r);
    }
    if(r>mid){
        sum += query(2*node+1, mid+1, end, l, r);
    }
    return sum;
}

void solve(){
    int n = 5;
    // [1, 1, 1, 1, 1]
    FOR(i, 1, n+1) arr[i] = 1;

    build(1, 1, n);

    cout << "Initial Sum [1, 5]: " << query(1, 1, n, 1, 5) << endl;

    cout << "Range Add [2, 4] with +10..." << endl;
    update(1, 1, n, 2, 4, 10);
    // [1, 11, 11, 11, 1]

    cout << "New Sum [1, 5]: " << query(1, 1, n, 1, 5) << endl;
    cout << "Check Index 3 ([3, 3]): " << query(1, 1, n, 3, 3) << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
