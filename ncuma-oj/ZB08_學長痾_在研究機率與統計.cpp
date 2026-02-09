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
    map<char, int>point = {{'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 1}};
    FOR(i, 2, 10) point.insert({'0'+i, i});
    map<char, int>folower = {{'S', 4}, {'H', 3}, {'D', 2}, {'C', 1}};
    string ansmp[9] = {"Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pairs", "One Pair", "High Card"};

    while(true){
        vector<pair<int, int>>cards;
        string s;
        while(cin >> s){
            cards.PB({point[s[0]], folower[s[1]]});
            if(cards.size()==5) break;
        }
        if(cards.size()==0) break;

        sort(ALL(cards));
        // FOR(i, 0, 5){
        //     cout << cards[i].F << ' ' << cards[i].S << endl;
        // }

        int ans = 8;
        bool five_color = true;
        bool five_num = true;
        bool four_kind = false;
        bool full_house = false;
        bool three_kind = false;
        bool two_pair = false;
        bool one_pair = false;

        FOR(i, 0, 4) if(cards[i].S!=cards[i+1].S) five_color = false;
        FOR(i, 0, 4) if(cards[i].F+1!=cards[i+1].F) five_num = false;
        if(!five_num and cards[0].F==1 and cards[1].F==10 and cards[2].F==11 and cards[3].F==12 and cards[4].F==13) five_num = true;
        if(cards[0].F==cards[3].F or cards[1].F==cards[4].F) four_kind = true;
        if((cards[0].F==cards[2].F and cards[3].F==cards[4].F) or (cards[0].F==cards[1].F and cards[2].F==cards[4].F)) full_house = true;
        if(cards[0].F==cards[2].F or cards[1].F==cards[3].F or cards[2].F==cards[4].F) three_kind = true;
        if((cards[0].F==cards[1].F and (cards[2].F==cards[3].F or cards[3].F==cards[4].F)) or (cards[1].F==cards[2].F and cards[3].F==cards[4].F)) two_pair = true;
        FOR(i, 0, 4) if(cards[i].F==cards[i+1].F) one_pair = true;

        if(five_color and five_num) ans = 0;
        else if(four_kind) ans = 1;
        else if(full_house) ans = 2;
        else if(five_color) ans = 3;
        else if(five_num) ans = 4;
        else if(three_kind) ans = 5;
        else if(two_pair) ans = 6;
        else if(one_pair) ans = 7;
        else ans = 8;

        cout << ansmp[ans] << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
