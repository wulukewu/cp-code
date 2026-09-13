/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc402_b — Restaurant Queue
 * Problem URL:    https://atcoder.jp/contests/abc402/tasks/abc402_b
 *
 * Matched result: AC
 * Submission:     #65002972
 * Submission URL: https://atcoder.jp/contests/abc402/submissions/65002972
 * Submitted:      2025-04-19 20:06:02 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         200.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-04-19 22:00:40 +0800
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
    
    int q;
    cin >> q;
    
    int t, x;
    queue < int > arr;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> x;
            arr.push(x);
        }else{
            cout << arr.front() << endl;
            arr.pop();
        }
    }
}
