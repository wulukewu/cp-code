/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc410_b — Reverse Proxy
 * Problem URL:    https://atcoder.jp/contests/abc410/tasks/abc410_b
 *
 * Matched result: AC
 * Submission:     #66732302
 * Submission URL: https://atcoder.jp/contests/abc410/submissions/66732302
 * Submitted:      2025-06-14 20:11:58 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         200.0
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

    vector < int > arr(n, 0);

    int x;
    for(int i=0; i<q; i++){
        int ans;
        cin >> x;
        if(x>=1){
            arr[x-1]++;
            ans = x-1;
        }else{
            int y = 0;
            for(int j=0; j<n; j++){
                if(arr[j] < arr[y]){
                    y = j;
                }
            }
            arr[y]++;
            ans = y;
        }

        // for(int j=0; j<n; j++){
        //     cout << arr[j] << ' ';
        // }
        // cout << endl;
        cout << ans + 1 << ' ';
    }
}
