// ==================================================
// Problem   : 106059E.cpp - Unknown
// URL       : https://codeforces.com/contest/106059/problem/E.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
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
ll POW(ll a, ll b) {ll res=1;; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1); return res;}
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n, q, l,r,last;
    last = -1;
    cin >> n >> q >> l >> r;
    vector<int> a;
    vector<int> b;
    vector<int> bsort;

    // int maxnum = max(a[a.size()-1], bsort[bsort.size()-1]);
    // vector<int> dp1(maxnum + 1, 0);
    // vector<int> dp2(maxnum + 1, 0);
    vector<int> dp1(1e8, 0);
    vector<int> dp2(1e8, 0);

    FOR(i, 0, n){
        int ai;
        cin >> ai;
        dp1[ai] += 1;
        dp2[ai] += ai;
        last = max(last,ai);
        // a.PB(ai);
    }

    FOR(i, 1, last+5){
        dp1[i] += dp1[i-1];
        dp2[i] += dp2[i-1];
    }


    FOR(i, 0, q){
        int bi;
        cin >> bi;
        int left_L = max(0,bi-r-1) , left_R = max(0,bi-l-1) , right_L = min(bi+l,last+1) , right_R = min(bi+r,last+1);
        int left_num = dp1[left_R] - dp1[left_L] , right_num = dp1[right_R] - dp1[right_L];
        int num = left_num + right_num;
        int dis;
        dis = (bi * left_num - (dp2[left_R] - dp2[left_L]) + (dp2[right_R] - dp2[right_L]) - bi * right_num);
        // cout << bi << " " << left_L << " " << left_R << " " << right_L << " " << right_R << endl;
        cout << num << " " << dis << endl;
        // b.PB(bi);
        // bsort.PB(bi);
    }

    // sort(ALL(a));
    // sort(ALL(bsort));



    // FOR(i, 1, maxnum+1)
    

}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}