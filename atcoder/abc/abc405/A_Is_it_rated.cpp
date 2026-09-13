/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc405_a — Is it rated?
 * Problem URL:    https://atcoder.jp/contests/abc405/tasks/abc405_a
 *
 * Matched result: AC
 * Submission:     #65630895
 * Submission URL: https://atcoder.jp/contests/abc405/submissions/65630895
 * Submitted:      2025-05-10 20:01:38 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        2 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-05-10 21:00:09 +0800
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
    int r, x;
    cin >> r >> x;

    if((1600<=r and r<=2999 and x==1) or (1200<=r and r<=2399 and x==2)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
