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

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    vector < int > arr(n);
    FOR(i, 0, n) cin >> arr[i];

    int d = y - x;
    int w_lower = 0;
    int w_upper = LLONG_MAX;
    int tar_rem = -1;

    FOR(i, 0, n){
        int cur_min_w = arr[i] * x;
        int cur_max_w = arr[i] * y;
        w_lower = max(w_lower, cur_min_w);
        w_upper = min(w_upper, cur_max_w);

        int cur_rem = (arr[i]*x) % d;
        if(tar_rem == -1){
            tar_rem = cur_rem;
        }else if(tar_rem != cur_rem){
            cout << -1 << endl;
            return;
        }
    }

    if(w_lower > w_upper){
        cout << -1 << endl;
        return;
    }

    int w_opt = w_upper - ((w_upper - tar_rem + d) % d);
    if(w_opt < w_lower){
        cout << -1 << endl;
        return;
    }

    int res = 0;
    FOR(i, 0, n){
        res += (w_opt - arr[i] * x) / d;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
