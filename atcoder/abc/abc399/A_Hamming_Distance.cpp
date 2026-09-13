/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc399_a — Hamming Distance
 * Problem URL:    https://atcoder.jp/contests/abc399/tasks/abc399_a
 *
 * Matched result: AC
 * Submission:     #64279732
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/64279732
 * Submitted:      2025-03-29 20:02:31 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-03-29 22:49:16 +0800
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
    string s, t;
    cin >> n >> s >> t;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    
    cout << ans;
}
