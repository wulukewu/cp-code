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
    string a, b;
    cin >> a >> b;

    auto normalize = [](string& s) -> string {
        vector<char> st;
        for (char c : s) {
            st.push_back(c);
            while (st.size() >= 4) {
                int sz = st.size();
                if (st[sz-4]=='(' && st[sz-3]=='x' && st[sz-2]=='x' && st[sz-1]==')') {
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                    st.push_back('x');
                    st.push_back('x');
                } else break;
            }
        }
        return string(st.begin(), st.end());

        // vector<string>st(1);
        // for(char c: s){
        //     if(c=='('){
        //         st.PB("");
        //     }else if(c==')' and st.size()>1){
        //         string inner = move(st.back());
        //         st.pop_back();

        //         bool det = true;
        //         for(char ch: inner){
        //             if(ch!='x'){
        //                 det = false;
        //                 break;
        //             }
        //         }
        //         if(det and inner.size()%2==0){
        //             st.back() += inner;
        //         }else{
        //             st.back() += '(';
        //             st.back() += inner;
        //             st.back() += ')';
        //         }
        //     }else{
        //         st.back() += c;
        //     }
        // }
        // while(st.size()>1){
        //     string top  = move(st.back());
        //     st.pop_back();
        //     st.back() += '(';
        //     st.back() += top;
        // }
        // return st[0];

        // vector<vector<string>>st(1);
        // for(char c: s){
        //     if(c=='('){
        //         st.PB({});
        //     }else if(c==')'){
        //         auto inner = st.back();
        //         st.pop_back();
        //         int n = inner.size();
        //         if(n%2==0){
        //             bool det = true;
        //             FOR(i, 0, n/2){
        //                 if(inner[i]!=inner[i+n/2]){
        //                     det = false;
        //                     break;
        //                 }
        //             }
        //             if(det){
        //                 FOR(i, 0, n/2){
        //                     st.back().PB(inner[i]);
        //                 }
        //                 FOR(i, 0, n/2){
        //                     st.back().PB(inner[i]);
        //                 }
        //                 continue;
        //             }
        //         }

        //         st.back().PB("(");
        //         for(auto& t: inner){
        //             st.back().PB(t);
        //         }
        //         st.back().PB(")");
        //     }else{
        //         st.back().PB(string(1, c));
        //     }
        // }

        // string res;
        // for(auto& t: st[0]) res += t;
        // return res;
    };

    a = normalize(a);
    b = normalize(b);

    // auto repAll = [](string& s, string from, string to) -> void {
    //     if(from.empty()) return;
    //     size_t pos = 0;
    //     while((pos = s.find(from, pos)) != std::string::npos) {
    //         s.replace(pos, from.length(), to);
    //         pos += to.length();
    //     }
    // };

    // int an = a.length()+1;
    // while(an>a.length()){
    //     an = a.length();
    //     repAll(a, "(xx)", "xx");
    // }
    // int bn = b.length()+1;
    // while(bn>b.length()){
    //     bn = b.length();
    //     repAll(b, "(xx)", "xx");
    // }

    // cout << a << ' ' << b << endl;
    if(a==b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
