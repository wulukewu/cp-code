/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       Codeforces
 * Problem:        105383A — Animal Farm
 * Problem URL:    https://codeforces.com/gym/105383/problem/A
 *
 * Matched result: AC
 * Submission:     #339440601
 * Submission URL: https://codeforces.com/gym/105383/submission/339440601
 * Submitted:      2025-09-20 07:00:28 +0800
 * Language:       C++23 (GCC 14-64, msys2)
 * Runtime:        280 ms
 * Memory:         200.0 KiB
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-09-20 13:03:16 +0800
 * Match policy:   matched by contest path and filename; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < string > a(n);
    vector < int > b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int m = 0;
    for(int i=0; i<n; i++){
        if(a[i]=="pig"){
            m = max(m, b[i]);
        }
    }

    int ans = m;
    for(int i=0; i<n; i++){
        if(a[i]!="pig" and b[i]<m){
            ans += b[i];
        }
    }
    cout << ans << endl;
}
