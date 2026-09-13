/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc410_a — G1
 * Problem URL:    https://atcoder.jp/contests/abc410/tasks/abc410_a
 *
 * Matched result: AC
 * Submission:     #66721611
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66721611
 * Submitted:      2025-06-14 20:02:56 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-06-15 23:14:56 +0800
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

    vector < int > a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int k;
    cin >> k;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(k<=a[i]) ans++;
    }

    cout << ans;
}
