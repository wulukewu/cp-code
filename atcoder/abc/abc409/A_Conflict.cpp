/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc409_a — Conflict
 * Problem URL:    https://atcoder.jp/contests/abc409/tasks/abc409_a
 *
 * Matched result: AC
 * Submission:     #66558728
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66558728
 * Submitted:      2025-06-07 20:57:32 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-06-07 21:42:09 +0800
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

    string t, a;
    cin >> t >> a;

    bool ans = false;
    for(int i=0; i<n; i++){
        if(t[i]=='o' and a[i]=='o'){
            ans = true;
            break;
        }
    }

    if(ans){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
