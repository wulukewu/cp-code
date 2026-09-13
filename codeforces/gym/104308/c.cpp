/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        104308C — Optimal Pairing
 * Problem URL:    https://codeforces.com/gym/104308/problem/C
 *
 * Matched result: AC
 * Submission:     #335250428
 * Submission URL: https://codeforces.com/gym/104308/submission/335250428
 * Submitted:      2025-08-24 12:59:23 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        62 ms
 * Memory:         0 B
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-08-24 17:06:00 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=n-1; i>=0; i-=2){
        ans += arr[i];
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
