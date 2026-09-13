/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104308B — Signature Nightmare
 * Problem URL:    https://codeforces.com/gym/104308/problem/B
 *
 * Matched result: AC
 * Submission:     #335259354
 * Submission URL: https://codeforces.com/gym/104308/submission/335259354
 * Submitted:      2025-08-24 14:10:10 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        108 ms
 * Memory:         100.0 KiB
 * Submissions:    1 total / 1 accepted
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
    vector<int> a(n), b(n);
    int sumA = 0, sumB = 0;
    FOR(i, 0, n){
        cin >> a[i];
        sumA += a[i];
    }
    FOR(i, 0, n){
        cin >> b[i];
        sumB += b[i];
    }

    auto can = [&](int x){
        int need = 0;
        FOR(i, 0, n){
            int req = x * a[i];
            if(req > b[i]){
                need += req - b[i];
            }
            if(need > k){
                return false;
            }
        }
        return need <= k;
    };

    int L = 0, R = (sumB + k) / sumA, ans = 0;
    while(L <= R){
        int mid = (L+R) / 2;
        if(can(mid)){
            ans = mid;
            L = mid + 1;
        }else{
            R = mid - 1;
        }
    }

    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
