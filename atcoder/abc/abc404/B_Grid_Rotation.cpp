/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc404_b — Grid Rotation
 * Problem URL:    https://atcoder.jp/contests/abc404/tasks/abc404_b
 *
 * Matched result: AC
 * Submission:     #65446414
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65446414
 * Submitted:      2025-05-03 20:32:34 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        2 ms
 * Points:         250.0
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-05-03 22:26:32 +0800
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
    int n;
    cin >> n;

    vector < vector < char > > s(n, vector < char > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    vector < vector < char > > t(n, vector < char > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> t[i][j];
        }
    }

    int ans = 1e9;
    for(int rot=0; rot<4; rot++){
        int diff = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i][j] != t[i][j]){
                    diff++;
                }
            }
        }

        ans = min(ans, diff + rot);
        vector < vector < char > > next_s(n, vector < char > (n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                next_s[j][n-1-i] = s[i][j];
            }
        }
        s = next_s;
    }
    cout << ans << endl;
}
