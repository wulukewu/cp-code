/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104059K — K.O. Kids
 * Problem URL:    https://codeforces.com/gym/104059/problem/K
 *
 * Matched result: AC
 * Submission:     #388677136
 * Submission URL: https://codeforces.com/gym/104059/submission/388677136
 * Submitted:      2026-08-28 20:45:07 +0800
 * Language:       C++20 (GCC 13-64)
 * Runtime:        46 ms
 * Memory:         100.0 KiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2026-08-28 23:41:51 +0800
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
//#define float double
//#define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u : a){
        cout << u << ' ';
    }
    cout << endl;
}

#ifdef LOCAL
template<class...  T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define dbg(...) ((void)0)
#endif

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool left = true;
    FOR(i, 0, n){
        if(s[i]=='L' and left){
            left = !left;
            continue;
        }
        if(s[i]=='R' and !left){
            left = !left;
            continue;
        }
        k--;
    }
    cout << max(k, 0ll) << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}
