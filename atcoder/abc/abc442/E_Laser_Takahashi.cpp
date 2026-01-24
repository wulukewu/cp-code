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
void dividemod(ll &a, ll b){a = a * POW(b, MOD-2) % MOD;}
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

#define double long double
void solve(){
    int n, q;
    cin >> n >> q;

    double pi = acos(-1.0);

    vector<double>v(n);
    vector<double>arr(n);
    FOR(i, 0, n){
        int x, y;
        cin >> x >> y;
        double theta = atan((double)y/(double)x);
        if(x<0){
            theta += pi;
        }else if(y<0){
            theta += 2 * pi;
        }
        // cout << theta << endl;
        v[i] = theta;
        arr[i] = theta;
    }
    sort(ALL(v));
    // print(v);

    FOR(i, 0, q){
        int a, b;
        cin >> a >> b;

        double ta = arr[a-1];
        double tb = arr[b-1];
        // cout << ta << ' ' << tb << endl;
        int ra = upper_bound(ALL(v), ta) - v.begin() - 1;
        int rb = lower_bound(ALL(v), tb) - v.begin();
        int res = (ra-rb+n)%n+1;
        cout << res << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
