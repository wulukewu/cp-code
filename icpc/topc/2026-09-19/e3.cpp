#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u: a){
        cout << u << ' ';
    }
    cout << endl;
}
#ifdef LOCAL
template<class.. T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' ', ...));
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define dbg(...) ((void)0)
#endif

using uint = unsigned;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
template<typename T>using Prior = priority_queue<T>;
template<typename T>using prior = priority_queue<T, vector<T>, greater<T>>;
const ll MOD = 1e9 + 7;
const double EPS = 1e9-7;
void addmod(ll &a, ll b) {a = (a+b)%MOD;}
void submod(ll &a, ll b) {a = (a-b+MOD)%MOD;}

void solve(){
    int n;
    cin >> n;
    int n2 = n*n;
    vector<vector<int>>v(n, vector<int>(n));
    FOR(i, 0, n){
        FOR(j, 0, n){
            cin >> v[i][j];
        }
    }

    vector<bool>red(n2, false);
    vector<bool>blue(n2, false);
    FOR(i, 0, n){
        FOR(j, 0, n){
            if(n*i+1<=v[i][j] and v[i][j]<=n*(i+1)){
                red[v[i][j]-1] = true;
            }
            if(v[i][j]%n==(j+1)%n){
                blue[v[i][j]-1] = true;
            }
        }
    }
    // print(red);
    // print(blue);
    
    
    FOR(i, 0, n){
        FOR(j, 0, n){
            int r = v[i][j]/n;
            int c = v[i][j]%n;
            // cout << v[i][j] << ' ' << r << ' ' << c << endl;
            if(red[v[i][j]-1] and !blue[v[i][j]-1]){
                FOR(k, min(j, c), max(j, c)){
                    // cout << r << ' ' << k << ' ' << v[r][k] << endl;
                    red[v[r][k]-1] = false;
                }
            }
            if(blue[v[i][j]-1]){
                FOR(k, min(i, r), max(i, r)){
                    // cout << k << ' ' << c << ' ' << v[k][c] << endl;
                    blue[v[k][c]-1] = false;
                }
            }
        }
    }
    // print(red);
    // print(blue);

    FOR(i, 0, n2){
        if(!red[i] and !blue[i]){
            // cout << i << endl;
            // cout << "No" << endl;
            cout << "Yes" << endl;
            return;
        }
    }
    // cout << "Yes" << endl;
    cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}