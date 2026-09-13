/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc406_c — ~
 * Problem URL:    https://atcoder.jp/contests/abc406/tasks/abc406_c
 *
 * Matched result: TLE
 * Submission:     #65914424
 * Submission URL: https://atcoder.jp/contests/abc406/submissions/65914424
 * Submitted:      2025-05-17 21:20:07 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        2210 ms
 * Points:         0.0
 * Submissions:    1 total / 0 accepted
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
    int n;
    cin >> n;

    vector < int > p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    vector < int > a(n, 0);
    vector < int > b(n, 0);
    for(int i=1; i<n-1; i++){
        if(p[i-1]<p[i] and p[i]>p[i+1]){
            a[i] = 1;
        }else if(p[i-1]>p[i] and p[i]<p[i+1]){
            b[i] = 1;
        }
    }

    for(int i=1; i<n; i++){
        a[i] += a[i-1];
        b[i] += b[i-1];
    }

    // for(int i=0; i<n; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;

    int ans = 0;
    for(int l=1; l<n-1; l++){
        int r = l+2;
        while(r<n){
            // cout << "l=" << l << ' ' << "r=" << r << endl;
            // for(int i=l-1; i<=r; i++){
            //     cout << p[i] << ' ';
            // }
            // cout << endl;
            
            if(p[l-1]<p[l] and a[r-1]-a[l-1]==1 and b[r-1]-b[l-1]==1){
                // for(int i=l-1; i<=r; i++){
                //     cout << p[i] << ' ';
                // }
                // cout << endl;
                ans++;
            }
            r++;
        }
    }

    cout << ans;
}
