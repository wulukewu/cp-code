// ==================================================
// Problem   : ABC434_D - Clouds
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc434/tasks/abc434_d
// ==================================================

#include <bits/stdc++.h>
using namespace std;

#define F first 
#define S second
#define ALL(v) v.begin(),v.end()
#define EB emplace_back
#define PB push_back
#define endl '\n'
//#define int long long
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

struct st{
    int u;
    int d;
    int l;
    int r;
};

void solve() {
    const int m = 2003;

    int n;
    cin >> n;

    vector < st > arr(n);
    vector < vector < int > >v(m, vector < int > (m+1, 0));

    int u, d, l, r;
    FOR(i, 0, n){
        cin >> u >> d >> l >> r;
        // u--;
        // d--;
        // l--;
        // r--;
        v[u][l]++;
        v[d+1][l]--;
        v[u][r+1]--;
        v[d+1][r+1]++;
        arr[i].u = u;
        arr[i].d = d;
        arr[i].l = l;
        arr[i].r = r;
    }

    FOR(i, 1, m){
        FOR(j, 1, m){
            v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }
    
    int cnt = 0;
    FOR(i, 1, m){
        FOR(j, 1, m){
            if(v[i][j]) cnt++;
            if(v[i][j]>=2) v[i][j] = 1;
            else v[i][j] = 0;
        }
    }
    
    FOR(i, 1, m){
        FOR(j, 1, m){
            v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
        }
    }

    // FOR(i, 1, 11){
    //     FOR(j, 1, 11){
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int ans;
    FOR(i, 0, n){
        int u = arr[i].u;
        int d = arr[i].d;
        int l = arr[i].l;
        int r = arr[i].r;
        ans = 4e6 - cnt + (d-u+1)*(r-l+1);
        int mi = v[d][r] - v[u-1][r] - v[d][l-1] + v[u-1][l-1];
        ans -= mi;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
