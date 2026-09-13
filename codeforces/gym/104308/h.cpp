/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104308H — Wonder Island
 * Problem URL:    https://codeforces.com/gym/104308/problem/H
 *
 * Matched result: AC
 * Submission:     #335270947
 * Submission URL: https://codeforces.com/gym/104308/submission/335270947
 * Submitted:      2025-08-24 15:37:47 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        436 ms
 * Memory:         100.0 KiB
 * Submissions:    2 total / 1 accepted
 * File commit:    2025-08-24 17:06:00 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long
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
ll POW(ll a, ll b) { ll res=1; do{if(b%2)timesmod(res,a);timesmod(a,a);}while(b>>=1);return res;}
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    cout << endl;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(k);

    v[0] = n;
    v[1] = n;
    v[2] = n;

    FOR(i, 3, k){
        v[i] = (v[i-1] + v[i-3]) % MOD;
    }

    cout << (v[k-1] * 2) % MOD << endl;


}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    FOR(i, 0, t){
        cout << "Case " << i + 1 << ": ";
        solve();
    }
    return 0;
}
