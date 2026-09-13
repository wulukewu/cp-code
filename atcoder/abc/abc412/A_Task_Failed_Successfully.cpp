/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc412_a — Task Failed Successfully
 * Problem URL:    https://atcoder.jp/contests/abc412/tasks/abc412_a
 *
 * Matched result: AC
 * Submission:     #67116386
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67116386
 * Submitted:      2025-06-28 20:01:05 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-06-28 21:46:58 +0800
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
    
    int m = 0;
    int a, b;
    while(n--){
        cin >> a >> b;
        if(b>a) m++;
    }

    cout << m;
}
