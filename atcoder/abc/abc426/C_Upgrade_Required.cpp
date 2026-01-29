// ==================================================
// Problem   : ABC426_C - Upgrade Required
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc426/tasks/abc426_c
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

const int INF = 2e6;
vector < int > bit(INF, 0);

int lb(int x){
    return x & -x;
}

void add(int x, int y){
    for(int i=x; i<INF; i+=lb(i)){
        bit[i] += y;
    }
}

int sum(int x){
    int res = 0;
    for(int i=x; i>0; i-=lb(i)){
        res += bit[i];
    }
    return res;
}

void solve() {
    int n, q;
    cin >> n >> q;

    FOR(i, 1, n+1){
        add(i, 1);
    }

    int x, y;
    FOR(qq, 0, q){
        cin >> x >> y;
        
        // FOR(i, 0, n+1){
        //     cout << sum(i) << ' ';
        // }
        // cout << endl;

        int a = sum(x);
        a = max(0, a);
        cout << a << endl;
        add(1, -a);
        add(y, a);
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
