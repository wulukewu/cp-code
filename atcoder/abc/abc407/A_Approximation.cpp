/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc407_a — Approximation
 * Problem URL:    https://atcoder.jp/contests/abc407/tasks/abc407_a
 *
 * Matched result: AC
 * Submission:     #66098063
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66098063
 * Submitted:      2025-05-24 20:15:02 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         150.0
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-05-26 10:46:51 +0800
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
    int a, b;
    cin >> a >> b;

    int c = a/b;
    if(b-(a%b)>(a%b)){}
    else c++;
    cout << c;
}
