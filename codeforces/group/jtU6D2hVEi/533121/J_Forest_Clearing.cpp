// ==================================================
// Problem   : jtU6D2hVEiJ - Unknown
// URL       : https://codeforces.com/contest/jtU6D2hVEi/problem/J
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

void solve() {
    int a, k, b, m, x;
    cin >> a >> k >> b >> m >> x;

    int l = 1;
    int r = 2 * x;

    int ans = r;
    while(l<=r){
        int mid = l + (r-l) / 2;

        int y = 0;
        if((mid - mid / k) > x / a){
            y = x + 1;
        }else{
            y += a * (mid - mid / k);
        }
        if((mid - mid / m) > x / b){
            y = x + 1;
        }else{
            y += b * (mid - mid / m);
        }
        
        if(y>=x){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
