// ==================================================
// Problem   : 2182B - New Year Cake
// Tags      : brute force
// Runtime   : 31 ms
// Memory    : 100 KB
// URL       : https://codeforces.com/contest/2182/problem/B
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

void solve() {
    int a, b;
    cin >> a >> b;

    int x, y, z;

    int cnt1 = 0;
    x = a;
    y = b;
    z = 1;
    FOR(i, 0, max(a, b)){
        if(i%2==1){
            x -= z;
        }else{
            y -= z;
        }
        z *= 2;
        if(x>=0 and y>=0) cnt1++;
        else break;
    }
    // cout << cnt1 << endl;

    int cnt2 = 0;
    x = a;
    y = b;
    z = 1;
    FOR(i, 0, max(a, b)){
        if(i%2==0){
            x -= z;
        }else{
            y -= z;
        }
        z *= 2;
        if(x>=0 and y>=0) cnt2++;
        else break;
    }
    // cout << cnt2 << endl;

    cout << max(cnt1, cnt2) << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
