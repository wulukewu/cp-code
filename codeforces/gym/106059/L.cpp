/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        106059L — Lantern Festival
 * Problem URL:    https://codeforces.com/gym/106059/problem/L
 *
 * Matched result: AC
 * Submission:     #339072289
 * Submission URL: https://codeforces.com/gym/106059/submission/339072289
 * Submitted:      2025-09-17 20:19:23 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        62 ms
 * Memory:         0 B
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-09-18 08:23:08 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int x;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==1) ans++;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
