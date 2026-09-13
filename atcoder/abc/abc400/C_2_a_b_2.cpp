/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc400_c — 2^a b^2
 * Problem URL:    https://atcoder.jp/contests/abc400/tasks/abc400_c
 *
 * Matched result: AC
 * Submission:     #64516757
 * Submission URL: https://atcoder.jp/contests/abc400/submissions/64516757
 * Submitted:      2025-04-05 20:13:50 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1915 ms
 * Points:         350.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-04-05 21:43:25 +0800
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

    int ans = 0;
    int a, b;
    for(int i=1; i<=(int)sqrt(n); i++){
        if(i%2==0)continue;
        // cout << i << endl;
        a = i * i;
        b = n / a;
        // cout << a << ' ' << b << endl;
        b /= 2;
        while(b>0){
            ans++;
            b /= 2;
        }
        // cout << ans << endl;
    }

    cout << ans;
}
