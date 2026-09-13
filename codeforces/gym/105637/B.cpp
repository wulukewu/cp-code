/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105637B — Flower Festival
 * Problem URL:    https://codeforces.com/gym/105637/problem/B
 *
 * Matched result: AC
 * Submission:     #336844508
 * Submission URL: https://codeforces.com/gym/105637/submission/336844508
 * Submitted:      2025-09-04 16:32:24 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        46 ms
 * Memory:         0 B
 * Submissions:    4 total / 1 accepted
 * File commit:    2025-09-04 23:43:22 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, f;
    cin >> n >> f;

    int ansidx = 1;
    double anssecond = -1;
    for(int i = 1; i <= n; i++){
        double time;
        int where, speed;

        cin >> where >> speed;
        time = (f - where) / speed;

        if(anssecond == -1 or time < anssecond){
            ansidx = i;
            anssecond = time;
        }
    }

    cout << ansidx << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
