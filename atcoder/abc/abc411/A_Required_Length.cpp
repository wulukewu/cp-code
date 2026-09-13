/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc411_a — Required Length
 * Problem URL:    https://atcoder.jp/contests/abc411/tasks/abc411_a
 *
 * Matched result: AC
 * Submission:     #66925300
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66925300
 * Submitted:      2025-06-21 20:01:02 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-06-21 21:44:43 +0800
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
    string p;
    cin >> p;

    int l;
    cin >> l;

    if(p.size()>=l){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
