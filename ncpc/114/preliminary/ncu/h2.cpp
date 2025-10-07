#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
ll MOD = 1e9 + 7;
const double EPS = 1e-9;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;} 
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}

ll extgcd(ll x, ll y, ll &a, ll &b) {
    if (y == 0) {
        a = 1;
        b = 0;
        return x;
    }
    ll ap, bp;
    ll ret = extgcd(y, x % y, ap, bp);
    a = bp;
    b = ap - bp * (x / y);
    return ret;
}

ll ceil_div(ll p, ll q){
    return (p >= 0) ? (p + q - 1) / q : p / q;
}


ll fd(ll A, ll B, ll C) {
    ll g = gcd(A, B);
    if (C % g != 0) return - 1;
    
    ll a = A/g, b = B/g, c = C/g;
    ll s, t, x, y;
    MOD = abs(b);
    extgcd((a%MOD+MOD)%MOD, MOD, s, t);
    x = (s * c) % b;
    if (x < 0) x += b;
    y = (C - A * x) / B;
    ll kx = ceil_div(-x, b);
    ll ky = ceil_div(-y, -(A/g));
    ll k  = max(kx, ky);
    x = x + b * k;
    y = y - a * k;
    return B * y;
}

void solve() {
    // // a - c = dy - bx
    // ll a, b, d; // ax + by = c 
    // cin >> a >> b >> d;
    // cout << fd(-b, d, a); // 回傳 by
    int n;
    cin >> n;
    vector<ll> t(n), v(n), die(n, -1);
    vector<bool> alive(n, 1);
    
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> v[i];
    }

    prior<tuple<ll,int,int>> pq;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll a = t[i], b = v[i], c = t[j], d = v[j];
              ll T = fd(-b, d, a - c);
              if (T != -1) { 
                  T = c + T;
                  pq.emplace(T, i, j);
              }
        }
    }
    
    while (!pq.empty()) {
        auto [T, i, j] = pq.top();
        pq.pop();
        if (!alive[i] or !alive[j]) continue;
        if (!(T >= t[i] and (T - t[i]) % v[i] == 0)) continue;
        if (!(T >= t[j] and (T - t[j]) % v[j] == 0)) continue;
        vector<int> gp;
        for (int u = 0; u < n; u++) {
            if (!alive[u]) continue;
            if (T >= t[u] and (T - t[u]) % v[u] == 0) {
                gp.EB(u);
            }
        }
        if (gp.size() <= 1) continue;
        for (auto u: gp) {
            alive[u] = 0;
            die[u] = T;
        }
    }
    
    for (auto i : die) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}