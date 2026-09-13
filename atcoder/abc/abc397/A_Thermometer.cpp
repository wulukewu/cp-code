/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc397_a — Thermometer
 * Problem URL:    https://atcoder.jp/contests/abc397/tasks/abc397_a
 *
 * Matched result: AC
 * Submission:     #63762235
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/63762235
 * Submitted:      2025-03-15 20:01:57 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-03-15 22:36:26 +0800
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    float x;
    cin >> x;

    if(x >= 38){
        cout << 1;
    }else if(x >= 37.5){
        cout << 2;
    }else{
        cout << 3;
    }

}
