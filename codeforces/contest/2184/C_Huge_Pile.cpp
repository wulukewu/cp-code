// ==================================================
// Problem   : 2184C - Huge Pile
// Tags      : binary search, dfs and similar, dp, graphs, math
// URL       : https://codeforces.com/contest/2184/problem/C
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

void solve(){
    int n, k;
    cin >> n >> k;

    int cnt = 0;
    bool det=false;
    while(n>0){
        if(n%2) det = true;
        if(n==k){
            cout << cnt << endl;
            return;
        }
        n /= 2;
        cnt++;
        if(n==k or (n+1==k and det)){
            cout << cnt << endl;
            return;
        }
    }
    cout << -1 << endl;

    // vector<int>arr;
    // vector<int>brr;
    // while(n>0){
    //     arr.PB(n%2);
    //     n /= 2;
    // }
    // reverse(ALL(arr));
    // print(arr);
    // while(k>0){
    //     brr.PB(k%2);
    //     k /= 2;
    // }
    // reverse(ALL(brr));
    // print(brr);

    // int ans = arr.size() - brr.size();

    // int ans = -1;
    // queue<pair<int, int>>q;
    // q.push({k, 0});
    // while(!q.empty()){
    //     auto t = q.front();
    //     q.pop();

    //     int x = t.F;
    //     int y = t.S;

    //     if(x==n){
    //         ans = y;
    //         break;
    //     }

    //     if(x>n) continue;
    //     q.push({x*2, y+1});
    //     q.push({x*2+1, y+1});
    // }
    // cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
