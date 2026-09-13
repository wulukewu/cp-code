/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105168A — Crazy Yesterday
 * Problem URL:    https://codeforces.com/gym/105168/problem/A
 *
 * Matched result: AC
 * Submission:     #333087027
 * Submission URL: https://codeforces.com/gym/105168/submission/333087027
 * Submitted:      2025-08-09 13:12:10 +0800
 * Language:       C++17 (GCC 7-32)
 * Runtime:        390 ms
 * Memory:         0 B
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
#define FOR(i, a , b) for(int i = a; i< a; i< b)

void solve(){
    int n;
    cin >> n;
    int in;
    while(n--){
        cin >> in;
        if(in == 1) in += 7;
        cout << in-1 << endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
