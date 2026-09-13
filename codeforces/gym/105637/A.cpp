/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105637A — Final Price
 * Problem URL:    https://codeforces.com/gym/105637/problem/A
 *
 * Matched result: AC
 * Submission:     #336841664
 * Submission URL: https://codeforces.com/gym/105637/submission/336841664
 * Submitted:      2025-09-04 15:59:06 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        61 ms
 * Memory:         0 B
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-09-04 23:43:22 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0,in;
    while(n--){
        cin >> in;
        ans += in;
    }
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
