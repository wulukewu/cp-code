/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc408_d — Flip to Gather
 * Problem URL:    https://atcoder.jp/contests/abc408/tasks/abc408_d
 *
 * Matched result: WA
 * Submission:     #66350149
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66350149
 * Submitted:      2025-05-31 21:09:32 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        25 ms
 * Points:         0.0
 * Submissions:    1 total / 0 accepted
 * File commit:    2025-05-31 21:33:15 +0800
 * Match policy:   matched by contest path and filename/title; accepted submission nearest before file commit when possible
 * Source equality with the online submission is not verified.
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        vector < int > arr;
        int c = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(c>0){
                    arr.push_back(c);
                    c = 0;
                }
            }else{
                c++;
            }
        }
        if(c>0){
            arr.push_back(c);
            c = 0;
        }

        int m = arr.size();
        // for(int i=0; i<m; i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;

        if(m<=1){
            cout << 0 << endl;
        }else{
            int ans = 0;
            int M = 0;
            for(int i=0; i<m; i++){
                ans += arr[i];
                M = max(M, arr[i]);
            }
            ans -= M;
            cout << ans << endl;
        }
    }
}


// #include <iostream>
// #include <string>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int solve() {
//   int n;
//   cin >> n;
//   string s;
//   cin >> s;

//   int min_ops = n; 

//   for (int l = 0; l <= n; ++l) {
//     for (int r = l; r <= n; ++r) {
//       int ops = 0;
//       for (int i = 0; i < n; ++i) {
//         if (l <= i && i < r) {
//           if (s[i] == '0') {
//             ops++;
//           }
//         } else {
//           if (s[i] == '1') {
//             ops++;
//           }
//         }
//       }
//       min_ops = min(min_ops, ops);
//     }
//   }
//   return min_ops;
// }

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     cout << solve() << endl;
//   }
//   return 0;
// }
