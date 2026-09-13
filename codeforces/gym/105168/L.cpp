/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105168L — Terabyte Connection
 * Problem URL:    https://codeforces.com/gym/105168/problem/L
 *
 * Matched result: AC
 * Submission:     #333087401
 * Submission URL: https://codeforces.com/gym/105168/submission/333087401
 * Submitted:      2025-08-09 13:16:59 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        764 ms
 * Memory:         100.0 KiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-08-09 19:05:04 +0800
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
// #define int long long
#define FOR(i, a ,b) for(int i = a; i< b; i++)

void solve(){
    int n;
    cin >> n;

    int ans_p = 0;
    int ans_t = 0;

    int p, t;
    FOR(i, 0, n){
        cin >> p >> t;
        ans_p = max(ans_p, p);
        ans_t = max(ans_t, p+t);
    }

    cout << ans_p << ' ' << ans_t << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
