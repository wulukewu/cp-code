#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n' << flush
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


void solve(){
    string sa;
    FOR(i, 0, 26){
        sa += 'a'+i;
    }
    cout << "? " << sa << endl;
    int n;
    cin >> n;
    FOR(i, 0, n){
        int a;
        cin >> a;
    }

    vector<int>code(n);
    FOR(bit, 0, 5){
        string s;
        FOR(c, 0, 26){
            if((c>>bit)&1){
                s += 'a'+c;
            }
        }
        cout << "? " << s << endl;
        int k;
        cin >> k;
        FOR(i, 0, k){
            int pos;
            cin >> pos;
            pos--;
            code[pos] |= (1<<bit);
        }
    }
    string ans;
    FOR(i, 0, n){
        ans += 'a'+code[i];
    }
    cout << "! " << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}