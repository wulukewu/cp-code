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

void solve() {
    int n,mx = 0;
    cin >> n;
    vector<vector<int>> mons(n+1,{0,0});
    for(int i=1;i<=n;i++){
        cin >> mons[i][0];
        mons[i][1] = i;
        mx = max(mx,mons[i][0]);
    }
    sort(mons.begin(),mons.end());
    // for(int i=0;i<=n;i++) cout << mons[i][0] << "." << mons[i][1] << "   ";
    // cout << endl;

    int a=1,b=1,ma=-1,mb=-1,now=1;
    bool find = false;
    while(now <= n && a <= mx){
        if(ma == -1){
            if(mons[now][0] == a){
                ma = mons[now][1];
                now++;
            }
            else if(mons[now][0] < a){
                now++;
            }
            else{
                int temp = a+b;
                a = b;
                b = temp;
            }
        }
        else if(mb == -1){
            if(mons[now][0] == b){
                mb = mons[now][1];
                find = true;
                break;
            }
            else if(mons[now][0] < b){
                now++;
            }
            else{
                int temp = a+b;
                a = b;
                b = temp;
                ma = -1;
            }
        }
    }
    if(!find) cout << "impossible\n";
    else cout << ma << " " << mb << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}