/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc410_c — Rotatable Array
 * Problem URL:    https://atcoder.jp/contests/abc410/tasks/abc410_c
 *
 * Matched result: AC
 * Submission:     #66736454
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66736454
 * Submitted:      2025-06-14 20:16:36 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        382 ms
 * Points:         300.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-06-15 23:14:56 +0800
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
    int n, q;
    cin >> n >> q;

    vector < int > a(n);
    for(int i=0; i<n; i++){
        a[i] = i+1;
    }

    int m = 0;
    int t;
    while(cin >> t){
        if(t==1){
            int p, x;
            cin >> p >> x;

            a[(p-1+m)%n] = x;
        }else if(t==2){
            int p;
            cin >> p;

            cout << a[(p-1+m)%n] << endl;
        }else{
            int k;
            cin >> k;

            m += k;
        }
    }
}
