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
// #define FOR(i, a, b) for(int i = a; i < b; i++)
// template<typename T>
// void print(T a){
//     for(auto u: a){
//         cout << u << ' ';
//     }
//     cout << endl;
// }
// #ifdef LOCAL
// template<class... T>void dbg(T... x) {
//     char e{};
//     ((cerr << e << x, e = ' '), ...);
// }
// #define debug(x...) dbg(#x, '=', x, '\n')
// #else
// #define dbg(...) ((void)0)
// #endif

// using uint = unsigned;
// using ull = unsigned int long long;
// using ll = long long;
// using ld = long double;
// template<typename T> using Prior = priority_queue<T>;
// template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;
// const ll MOD = 1e9+7;
// const double EPS = 1e-9;
// void addmod(ll &a, ll b) {a = (a+b)%MOD};
// void submod(ll &a, ll b) {a = (a-b+MOD)%MOD};


void solve() {
    int n;
    cin >> n;
    vector<int> good(n);
    for(int i=0;i<n;i++){
        cin >> good[i];
    }
    for(int i=0;i<n;i++){
        int bad;
        cin >> bad;
        good[i] -= bad;
    }
    int dif = -good[0];
    if(dif < 0){
        cout << 0 << endl;
        return;
    }
    bool ok = true;
    for(int i=0;i<n;i++){
        good[i] += dif;
        if(good[i] > 0){
            ok = true;
            break;
        }
        if(good[i] < 0){
            ok = false;
            break;
        }
    }
    if(ok) cout << dif << endl;
    else cout << dif+1 << endl;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
