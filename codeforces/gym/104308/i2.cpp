// ==================================================
// Problem   : 104308I2 - Unknown
// URL       : https://codeforces.com/contest/104308/problem/I2
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
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
ll POW(ll a, ll b) { ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1);return res;}
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

template <class T>
struct BIT { 
    int n;
    vector<T> a;
    BIT(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) { // [l, r)
        return sum(r) - sum(l);
    }
    
    
    int select(const T &k) { // 前綴區間和 >= k 的位置
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n and cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector < int > c(n);
    map < int, int > mp;
    int t = q + 5;
    BIT < int > bt(q+n+10);

    FOR(i, 0, n){
        cin >> c[i];
        if(!mp.count(c[i])) mp[c[i]] = i+t+1;
        bt.add(i+t+1, 1);
    }

    int x;
    while(q--){
        cin >> x;
        cout << bt.sum(mp[x])+1 << endl;
        t--;
        bt.add(mp[x], -1);
        mp[x] = t;
        bt.add(t, 1);
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}