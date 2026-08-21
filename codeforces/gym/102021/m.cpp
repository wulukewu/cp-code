#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
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
    int m, n, q;
    cin >> m >> n >> q;
    vector<vector<int>>v(m, vector<int>(n));
    FOR(i, 0, m){
        FOR(j, 0, n){
            cin >> v[i][j];
        }
    }

    const int offs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int l = 1, r = 1e6+10;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            bool res = false;
            vector<vector<bool>>vis(m, vector<bool>(n, false));
            auto dfs = [&](auto&& self, int x, int y) -> void {
                if(v[x][y]>mid) return;
                if(res) return;
                if(x==x2 and y==y2){
                    res = true;
                    return;
                }
                FOR(k, 0, 4){
                    int row = x+offs[k][0];
                    int col = y+offs[k][1];
                    if(!(0<=row and row<m and 0<=col and col<n)) continue;
                    // if(v[row][col]>mid) continue;
                    if(vis[row][col]) continue;
                    vis[row][col] = true;
                    self(self, row, col);
                    // vis[row][col] = false;
                }
            };
            vis[x1][y1] = true;
            dfs(dfs, x1, y1);
            if(res){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}