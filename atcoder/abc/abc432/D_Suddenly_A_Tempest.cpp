// ==================================================
// Problem   : ABC432_D - Suddenly, A Tempest
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc432/tasks/abc432_d
// ==================================================

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
#define int long long
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
//#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
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
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
template <typename T>
void printQ(queue < T > q){
    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
template <typename T>
void printPQ(priority_queue < T > pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

bool overlap(int a1, int a2, int b1, int b2){
    return max(a1, b1) < min(a2, b2);
}
bool adjacent(pair < pair < int, int >, pair < int, int > > r1, pair < pair < int, int >, pair < int, int > > r2){
    if(overlap(r1.F.S, r1.S.S, r2.F.S, r2.S.S)){
        if(r1.S.F==r2.F.F or r1.F.F == r2.S.F) return true;
    }
    if(overlap(r1.F.F, r1.S.F, r2.F.F, r2.S.F)){
        if(r1.S.S==r2.F.S or r1.F.S == r2.S.S) return true;
    }
    return false;
}

vector < int > parent;
int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unite(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px != py) parent[px] = py;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    vector < pair < pair < int, int >, pair < int, int > > > v;
    v.PB({{0, 0}, {x, y}});
    
    char c;
    int a, b;
    FOR(i, 0, n){
        cin >> c >> a >> b;
        
        vector < pair < pair < int, int >, pair < int, int > > > v1;
        for(auto j: v){
            int xl = j.F.F;
            int yl = j.F.S;
            int xr = j.S.F;
            int yr = j.S.S;

            if(c=='X'){
                int left_xr = min(xr, a);
                if(xl < left_xr){
                    v1.PB({{xl, yl-b}, {left_xr, yr-b}});
                }
                int right_xl = max(xl, a);
                if(right_xl < xr){
                    v1.PB({{right_xl, yl+b}, {xr, yr+b}});
                }

                // if(xl <= a and a < xr){
                //     v1.PB({{xl, yl-b}, {a, yr-b}});
                //     v1.PB({{a, yl+b}, {xr, yr+b}});
                // }else{
                //     v1.PB({{xl, yl}, {xr, yr}});
                // }
            }else{
                int lower_yr = min(yr, a);
                if(yl < lower_yr){
                    v1.PB({{xl-b, yl}, {xr-b, lower_yr}});
                }
                int upper_yl = max(yl, a);
                if(upper_yl < yr){
                    v1.PB({{xl+b, upper_yl}, {xr+b, yr}});
                }
                // if(yl <= a and a < yr){
                //     v1.PB({{xl-b, yl}, {xr-b, a}});
                //     v1.PB({{xl+b, a}, {xr+b, yr}});
                // }else{
                //     v1.PB({{xl, yl}, {xr, yr}});
                // }
            }
        }
        v = v1;

        // for(auto j: v){
        //     cout << j.F.F << ' ' << j.F.S << ' ' << j.S.F << ' ' << j.S.S << endl;
        // }
        // cout << endl;
    }

    int num = v.size();
    parent.resize(num);
    FOR(i, 0, num){
        parent[i] = i;
    }

    FOR(i, 0, num){
        FOR(j, i+1, num){
            if(adjacent(v[i], v[j])){
                unite(i, j);
            }
        }
    }

    // print(parent);

    map < int, int > size_mp;
    FOR(i, 0, num){
        int p = find(i);
        int sz = (v[i].S.F - v[i].F.F) * (v[i].S.S - v[i].F.S);
        size_mp[p] += sz;
    }

    vector < int > ans;
    for(auto &kv: size_mp){
        ans.PB(kv.S);
    }
    sort(ALL(ans));

    cout << ans.size() << endl;
    print(ans);

    // vector < pair < int, vector < pair < pair < int, int >, pair < int, int > > > > > arr;
    // for(auto j: v){
    //     int xl = j.F.F;
    //     int yl = j.F.S;
    //     int xr = j.S.F;
    //     int yr = j.S.S;
        
    //     int m = (xr-xl) * (yr-yl);
        
    //     bool added = false;
        
    //     // for(auto &i: arr){
    //     //     int x2l = i.S.F.F;
    //     //     int y2l = i.S.F.S;
    //     //     int x2r = i.S.S.F;
    //     //     int y2r = i.S.S.S;
    //     // }

    //     if(!added){
    //         vector < pair < pair < int, int >, pair < int, int > > > brr;
    //         brr.PB({{xl, yl}, {xr, yr}});
    //         arr.PB({m, brr});
    //     }
    // }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
