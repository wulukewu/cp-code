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


void solve(){
    string s;
    cin >> s;

    vector<string> possible = {
        "hdcs", "hdsc", "hcds", "hcsd", "hsdc", "hscd",
        "dhcs", "dhsc", "dchs", "dcsh", "dshc", "dsch",
        "chds", "chsd", "cdhs", "cdsh", "cshd", "csdh",
        "shdc", "shcd", "sdhc", "sdch", "schd", "scdh"
    };

    int maxkeep = 0;

    for(int i = 0; i < 24; i++){
        string target = possible[i];

        vector<int> rankmap(256, 0);
        for (int j = 0; j < 4; j++) {
            rankmap[target[j]] = j;
        }

        vector<int> dp(4, 0);
        for(char c:s){
            int k = rankmap[c];
            int best = 0;

            for(int j = 0; j <= k; j++){
                best = max(best, dp[j]);
            }

            dp[k] = max(dp[k], best + 1);
        }

        for (int x : dp) {
            maxkeep = max(maxkeep, x);
        }
    }

    cout << s.size() - maxkeep << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}