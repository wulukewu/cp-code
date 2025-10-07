#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
#ifdef LOCAL
template<class... T> void dbg(T... x) {
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
void timesmod(ll &a, ll b) {a = (a*b)%MOD;}
ll POW(ll a, ll b) {ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
void dividemod(ll &a, ll b, ll c){a = a * POW(b, c-2) % c;}

int extgcd(int a, int b, int& x, int& y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;
    return g;
    // // a > b
    // if(a<b) swap(a, b);
    // if(b==1) return 1;
    // else if(a%b==0) return b;
    // else return gcd(b, a%b);
}

void solve() {
    int n;
    cin >> n;

    vector < pair < int, int > > v(n);
    FOR(i, 0, n) cin >> v[i].F >> v[i].S;

    // int xx, yy;
    // int gg = extgcd(48, 18, xx, yy);
    // cout << "Test: g=" << gg << ", x=" << xx << ", y=" << yy << endl;  // 應輸出 6 -1 3

    FOR(i, 0, n){
        FOR(j, i+1, n){
            int a, b, c;
            a = v[j].S;
            b = - v[i].S;
            c = v[i].F - v[j].F;
            if(a==0 and b==0 and c!=0) continue;

            int g = gcd(abs(a), abs(b));
            if(c%g!=0){
                cout << -1 << endl;
                continue;
            }
            int a2 = a / g;
            int b2 = abs(b) / g;
            int c2 = c / g;
            // cout << a2 << ' ' << b2 << ' ' << c2 << endl;
            
            if(b2==1){
                if(c2==0){
                    cout << v[i].F << endl;
                    // cout << "ti==tj" << endl;
                }else{
                    // cout << "no solution" << endl;
                    cout << -1 << endl;
                }
                continue;
            }
            // int x0 = c2;
            // cout << x0 << ' ' << a2 << ' ' << b2 << endl;
            // // dividemod(x0, a2, b2);
            // cout << x0 << endl;

            int xx, yy;
            extgcd(a2, b2, xx, yy);
            int x0 = (xx * c2 % b2 + b2) % b2;
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
