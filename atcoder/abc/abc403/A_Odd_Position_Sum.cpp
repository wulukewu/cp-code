/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc403_a — Odd Position Sum
 * Problem URL:    https://atcoder.jp/contests/abc403/tasks/abc403_a
 *
 * Matched result: AC
 * Submission:     #65238615
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65238615
 * Submitted:      2025-04-27 20:01:09 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-04-27 21:42:22 +0800
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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int s = 0;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        if(i%2==0){
            s += a;
        }
    }

    cout << s;
}
