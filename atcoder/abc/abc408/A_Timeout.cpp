/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc408_a — Timeout
 * Problem URL:    https://atcoder.jp/contests/abc408/tasks/abc408_a
 *
 * Matched result: AC
 * Submission:     #66309831
 * Submission URL: https://atcoder.jp/contests/abc408/submissions/66309831
 * Submitted:      2025-05-31 20:08:25 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         150.0
 * Submissions:    2 total / 1 accepted
 * File commit:    2025-05-31 21:33:15 +0800
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
    int n, s;
    cin >> n >> s;

    vector < int > t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    bool det = true;
    if(t[0]>s){
        det = false;
    }else{
        for(int i=0; i<n-1; i++){
            if(t[i+1]-t[i]>s){
                det = false;
                break;
            }
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
