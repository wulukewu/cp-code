// ==================================================
// Problem   : ABC415_D - Get Many Stickers
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc415/tasks/abc415_d
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
    int n, m;
    cin >> n >> m;

    vector < pair < int, int > > arr(m);
    FOR(i, 0, m) cin >> arr[i].F >> arr[i].S;

    vector < pair < int, int > > brr(m);
    FOR(i, 0, m){
        brr[i].F = arr[i].F-arr[i].S;
        brr[i].S = arr[i].F;
    }
    sort(ALL(brr));

    // FOR(i, 0, m){
    //     cout << brr[i].F << ' ' << brr[i].S << endl;
    // }

    int ans = 0;
    FOR(i, 0, m){
        if(brr[i].S>n) continue;

        // int stickers = n / brr[i].S;
        // n -= brr[i].F * stickers;
        // ans += stickers;
        // i--;

        int stickers = (n-brr[i].S)/brr[i].F+1;
        ans += stickers;
        n -= brr[i].F * stickers;
    }

    cout << ans << endl;

    // vector < pair < pair < int, int >, int > > arr(m);
    // FOR(i, 0, m){
    //     cin >> arr[i].F.F >> arr[i].F.S;
    //     // arr[i].S = (double) arr[i].F.S / arr[i].F.F;
    //     arr[i].S = arr[i].F.S - arr[i].F.F;
    // }

    // sort(ALL(arr));

    // vector < pair < int, int > > dp(m);
    // dp[0].F = arr[0].S;
    // dp[0].S = 0;
    // FOR(i, 1, m){
    //     if(arr[i].S>dp[i-1].F){
    //         dp[i].F = arr[i].S;
    //         dp[i].S = i;
    //     }else{
    //         dp[i].F = dp[i-1].F;
    //         dp[i].S = dp[i-1].S;
    //     }
    //     // dp[i] = max(dp[i-1], arr[i].S);
    // }

    // // FOR(i, 0, m){
    // //     cout << arr[i].F.F << ' ' << arr[i].F.S << ' ' << arr[i].S << endl;
    // // }

    // int ans = 0;
    // while(n>0){
    // // FOR(i, 0, 5){
    //     int l = 0, r = m-1;
    //     int idx = -1;
    //     while(l<=r){
    //         int mid = l + (r-l)/2;
    //         if(n>=arr[mid].F.F){
    //             l = mid + 1;
    //             idx = mid;
    //         }else{
    //             r = mid - 1;
    //         }
    //     }
    //     // cout << idx << endl;

    //     if(idx==-1) break;

    //     // int max_idx = -1;
    //     // FOR(i, 0, idx+1){
    //     //     if(max_idx==-1 or arr[i].S>arr[max_idx].S){
    //     //         max_idx = i;
    //     //     }
    //     // }
    //     // cout << max_idx << endl;
    //     int max_idx = dp[idx].S;

    //     // if(max_idx<0) break;

    //     int stickers = n / arr[max_idx].F.F;
    //     // cout << "stickers: " << stickers << endl;
    //     n %= arr[max_idx].F.F;
    //     n += arr[max_idx].F.S * stickers;
    //     ans += stickers;
    //     // cout << "n: " << n << endl;
    // }

    // cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
