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
    cin.ignore();
    vector<string>s(h+1);
    FOR(i, 0, h+1) getline(cin, s[i]);

    vector<vector<array<bool, 4>>>v(h, vector<array<bool, 4>>(w));
    FOR(i, 0, h){
        FOR(j, 0, w){
            // 0: up, 1: right, 2: down, 3: left
            if(s[i][2*j+1]==' ') v[i][j][0] = true;
            if(s[i+1][2*j+2]==' ') v[i][j][1] = true;
            if(s[i+1][2*j+1]==' ') v[i][j][2] = true;
            if(s[i+1][2*j]==' ') v[i][j][3] = true;
        }
    }

    // FOR(k, 0, 4){
    //     FOR(i, 0, h){
    //         FOR(j, 0, w){
    //             cout << v[i][j][k];
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    const int offs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int m;
    cin >> m;
    vector<pair<int, int>>route(m);
    FOR(i, 0, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        route[i] = {x, y};
    }
    int ans = 0;
    FOR(i, 0, m-1){
        int sx = route[i].F;
        int sy = route[i].S;
        int ex = route[i+1].F;
        int ey = route[i+1].S;
        queue<pair<int, pair<int, int>>>q;
        vector<vector<bool>>vis(h, vector<bool>(w, false));
        q.push({0, {sx, sy}});
        vis[sx][sy] = true;
        while(!q.empty()){
            auto [t, xy] = q.front();
            auto [x, y] = xy;
            q.pop();
            if(x==ex and y==ey){
                ans += t;
                break;
            }
            FOR(k, 0, 4){
                int r = x + offs[k][0];
                int c = y + offs[k][1];
                if(!(0<=r and r<h and 0<=c and c<w)) continue;
                if(!v[x][y][k]) continue;
                if(vis[r][c]) continue;
                vis[r][c] = true;
                q.push({t+1, {r, c}});
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}