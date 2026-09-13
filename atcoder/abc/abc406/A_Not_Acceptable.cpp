/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc406_a — Not Acceptable
 * Problem URL:    https://atcoder.jp/contests/abc406/tasks/abc406_a
 *
 * Matched result: AC
 * Submission:     #65849238
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65849238
 * Submitted:      2025-05-17 20:01:59 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-05-17 21:49:15 +0800
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a>c){
        cout << "Yes";
    }else if(a==c and b>d){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
