#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

#ifdef LOCAL
template<class...  T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define dbg(...) ((void)0)
#endif

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
void timesmod(ll &a, ll b) {a = (a*b) % MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res, a);timesmod(a,a);}while(b>>=1);return res;}
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}

template<class T>
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

    void add(int x, const T & v) {
        for(int i = x + 1; i <= n; i += i & -i) {
            a[i-1] += v;
        }
    }

    T sum(int x){
        T ans{};
        for(int i = x; i > 0; i -= i & -i){
            ans += a[i-1];
        }
        return ans;
    }

    T rangeSum(int l, int r){
        return sum(r) - sum(l);
    }
};


void solve(){
    int n, q;
    cin >> n >> q;

    BIT<int> bit(n);

    auto count = [&](int a, int b) {
        if (a <= b) {
            return bit.rangeSum(a, b + 1);
        } else {
            return bit.rangeSum(a, n) + bit.rangeSum(0, b + 1);
        }
    };

    while(q--){
        char type;
        cin >> type;
        if(type == '-'){
            int a;
            cin >> a;
            a -= 1;
            bit.add(a, 1);
        }else if(type == '+'){
            int a;
            cin >> a;
            a -= 1;
            bit.add(a, -1);
        }else if(type == '?'){
            int a, b;
            cin >> a >> b;
            a -= 1;
            b -= 1;

            int soon = count(a, b);
            int knee = count(b, a);

            if(soon == 0 or knee == 0){
                cout << "possible" << endl;
            }else{
                cout << "impossible" << endl;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}