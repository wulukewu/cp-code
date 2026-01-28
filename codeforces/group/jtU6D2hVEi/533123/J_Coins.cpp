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
    int n, m;
    cin >> n >> m;

    int a;
    set < int > aset;
    FOR(i, 0, m){
        cin >> a;
        if(aset.find(a)==aset.end()){
            aset.insert(a);
        }
    }

    vector < int > arr;
    for(int i: aset){
        arr.PB(i);
    }

    int total = 0;
    FOR(i, 0, m) total += arr[i];
    total *= 2;

    if(n>total){
        cout << -1 << endl;
        return;
    }

    vector < int > v(m, 0);
    int ans_cnt = 2*m+1;
    vector < int > ans(m, 0);
    auto dfs = [&](int rem, int idx, int coin_cnt, auto&& self) -> void {
        if(idx>=m){
            if(rem==0 and coin_cnt < ans_cnt){
                ans = v;
            }
            return;
        }else if(rem<0){
            return;
        }

        if(v[idx]<2){
            v[idx] += 1;
            self(rem-arr[idx], idx, coin_cnt+1, self);
            v[idx] -= 1;
        }
        self(rem, idx+1, coin_cnt, self);
    };

    dfs(n, 0, 0, dfs);

    // FOR(i, 0, m){
    //     cout << ans[i] << ' ';
    // }
    // cout << endl;

    int k = 0;
    FOR(i, 0, m){
        k += ans[i];
    }
    cout << k << endl;

    if(k>0){
        vector < int > ans_sort;
        FOR(i, 0, m){
            FOR(j, 0, ans[i]){
                // cout << arr[i] << ' ';
                ans_sort.PB(arr[i]);
            }
        }
        // cout << endl;
    
        sort(ALL(ans_sort));
    
        for(int i: ans_sort){
            cout << i << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t; 
    while (t--) solve();
    return 0;
}
