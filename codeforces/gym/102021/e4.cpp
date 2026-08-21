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
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
#ifdef LOCAL
template<class... T>void dbg(T... x) {
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
const ll MOD = 1e9+7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void timesmod(ll &a, ll b){a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res, a); timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b) {a = a * POW(b, MOD-2) % MOD;}

int gcd(int a, int b){
    if(a<b) swap(a, b);
    if(a%b==0) return b;
    return gcd(b, a%b);
}

void solve() {
    int m = 1e7+10;
    vector<bool>prime(m, true);
    prime[0] = false;
    prime[1] = false;
    FOR(i, 2, m){
        if(!prime[i]) continue;
        for(int j=2*i; j<m; j+=i){
            prime[j] = false;
        }
    }

    int n;
    cin >> n;
    while(n--){
        double a, b;
        cin >> a >> b;
        int p = llround(a*1e5);
        int q = llround(b*1e5);
        int g = gcd(p, q);
        p /= g;
        q /= g;
        // cout << p << ' ' << q << endl;

        if(p==1 and q==1){
            cout << "2 2" << endl;
        }else if(prime[p] and prime[q]){
            cout << p << ' ' << q << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}