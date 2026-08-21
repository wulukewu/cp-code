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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> c(h + 2, vector<int>(w + 2));
    FOR(i, 0, h + 2) {
        FOR(j, 0, w + 2) {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> ans(h + 3, vector<int>(w + 3, 0));

    FOR(i, 1, h+1){
        FOR(j, 1, w+1){
            int sum = 0;
            FOR(dx, -1, 2){
                FOR(dy, -1, 2){
                    int ni = (i - 1) + dx;
                    int nj = (j - 1) + dy;
                    if(ni >= 1 and ni <= h and nj >= 1 and nj <= w){
                        if (ni == i && nj == j) continue;
                        sum += ans[ni][nj];
                    }
                }
            }

            int val = c[i - 1][j - 1] - sum;
            if (val != 0 && val != 1) {
                cout << "impossible" << endl;
                return;
            }
            ans[i][j] = val;
        }
    }

    FOR(i, 0, h+2){
        FOR(j, 0, w+2){
            int cnt = 0;
            FOR(dx, -1, 2){
                FOR(dy, -1, 2){
                    int ni = i + dx;
                    int nj = j + dy;
                    if(ni >= 1 and ni <= h and nj >= 1 and nj <= w){
                        cnt += ans[ni][nj];
                    }
                }
            }
            if(cnt != c[i][j]){
                cout << "impossible" << endl;
                return;
            }
        }
    }

    FOR(i, 1, h+1){
        FOR(j, 1, w+1){
            if(ans[i][j]){
                cout << 'X';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }

}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}