/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc397_d — Cubes
 * Problem URL:    https://atcoder.jp/contests/abc397/tasks/abc397_d
 *
 * Matched result: WA
 * Submission:     #63831121
 * Submission URL: https://atcoder.jp/contests/abc397/submissions/63831121
 * Submitted:      2025-03-15 21:18:10 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        191 ms
 * Points:         0.0
 * Submissions:    4 total / 0 accepted
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
    
    int n;
    cin >> n;

    int m = 1e7;

    vector < int > arr(m);
    for(int i=0; i<m; i++){
        // arr[i] = pow((i+1), 3);
        arr[i] = (i+1)*(i+1)*(i+1);
    }

    int x=0;
    int goal;
    bool minus_one = false;
    for(int y=0; y<m; y++){
        goal = n + arr[y];
        while(arr[x]<goal){
            x++;
            if(x>=m){
                // cout << -1;
                minus_one = true;
                break;
            }
        }
        if(arr[x]==goal){
            cout << x+1 << ' ' << y+1;
            break;
        }
    }

    if(minus_one){
        cout << -1;
    }
}
