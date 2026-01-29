// ==================================================
// Problem   : ABC440_D - Forbidden List 2
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc440/tasks/abc440_d
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
    int n, q;
    cin >> n >> q;
    vector<int>arr(n);
    FOR(i, 0, n) cin >> arr[i];

    sort(ALL(arr));
    // print(arr);

    vector<int>brr(n);
    FOR(i, 0, n){
        brr[i] = arr[i] - (i+1);
    }
    // print(brr);

    while(q--){
        int x, y;
        cin >> x >> y;

        int a = lower_bound(ALL(arr), x) - arr.begin();
        int b = x-1-a;
        int tar = y + b;
        auto it = lower_bound(ALL(brr), tar);

        int ans;
        if(it==brr.end()){
            int lasta = arr[n-1];
            int lastb = brr[n-1];
            ans = lasta + tar - lastb;
        }else{
            int c = it - brr.begin();
            ans = arr[c] - (brr[c] - tar + 1);
        }
        cout << ans << endl;

        // auto itx = upper_bound(ALL(arr), x-1);
        // // int itx = upper_bound(ALL(arr), x-1) - arr.begin();

        // int l = x, r = 2e9+5;
        // // while(l<=r){
        // while(l+1<r){
        //     int mid = l + (r-l) / 2;
        //     // cout << "mid=" << mid << endl;
        //     // int itm = lower_bound(ALL(arr), mid) - arr.begin();
        //     // if(mid-itx+itm>=x+y){
        //     //     r = mid;
        //     // }else{
        //     //     l = mid;
        //     // }
        //     auto it = lower_bound(ALL(arr), mid);
        //     int a = it-itx;
        //     // cout << "a=" << a << endl;
        //     int b = mid - x - a;
        //     // cout << "b=" << b << endl;
        //     // if(mid-b)
        //     // if(b>y-1){
        //     //     // r = mid - 1;
        //     //     r = mid;
        //     // }else if(b<y-1){
        //     //     // l = mid + 1;
        //     //     l = mid;
        //     // }else{
        //     //     cout << mid << endl;
        //     //     break;
        //     // }
        // }
        // cout << l << endl;
    }

    // int m = 3e5+5;
    // vector<int>dp(m, 0);
    // FOR(i, 0, n){
    //     int a;
    //     cin >> a;
    //     dp[a]++;
    // }
    // FOR(i, 0, m-1){
    //     dp[i+1] += dp[i];
    // }
    // // print(dp);

    // while(q--){
    //     int x, y;
    //     cin >> x >> y;
    //     // cout << dp[x] << endl;
    // }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
