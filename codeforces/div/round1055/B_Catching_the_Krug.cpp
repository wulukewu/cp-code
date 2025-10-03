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
    int n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;

    int r, ar;
    if(rk>rd){
        r = n - rk;
    }else if(rk<rd){
        r = rk;
    }else{
        r = 0;
    }
    ar = abs(rk-rd) + r;

    int c, ac;
    if(ck>cd){
        c = n - ck;
    }else if(ck<cd){
        c = ck;
    }else{
        c = 0;
    }
    ac = abs(ck-cd) + c;

    int ans = max(ar, ac);
    cout << ans << endl;

    // int a, c;
    // if(rk>rd){
    //     a = n - rk;
    //     c = rk - rd;
    // }else{
    //     a = rk;
    //     c = rd - rk;
    // }
    // int b, d;
    // if(ck>=cd){
    //     b = n - ck;
    //     d = ck - cd;
    // }else{
    //     b = ck;
    //     d = cd - ck;
    // }
    // cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

    // int ans = max(a+c, b+d);
    // if(abs(c-d)<=1){
    //     ans = min(a+c, b+d);
    // }else{
    //     ans = max(a+c, b+d);
    // }
    // cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t; 
    while (t--) solve();
    return 0;
}
