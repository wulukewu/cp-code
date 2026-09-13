/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc413_a — Content Too Large
 * Problem URL:    https://atcoder.jp/contests/abc413/tasks/abc413_a
 *
 * Matched result: AC
 * Submission:     #67294683
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67294683
 * Submitted:      2025-07-05 20:01:38 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-07-05 22:19:41 +0800
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
    int n, m;
    cin >> n >> m;

    int a;
    int b = 0;
    for(int i=0; i<n; i++){
        cin >> a;
        b += a;
    }

    if(b<=m){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
