/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc402_d — Line Crossing
 * Problem URL:    https://atcoder.jp/contests/abc402/tasks/abc402_d
 *
 * Matched result: AC
 * Submission:     #65023334
 * Submission URL: https://atcoder.jp/contests/abc402/submissions/65023334
 * Submitted:      2025-04-19 20:43:59 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        112 ms
 * Points:         400.0
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
    
    int n, m;
    cin >> n >> m;

    vector < int > arr(n, 0);

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        arr[(b+a)%n]++;
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    int ans = m*(m-1)/2;
    for(int i=0; i<n; i++){
        if(arr[i]>=2){
            ans -= arr[i]*(arr[i]-1)/2;
        }
    }

    cout << ans;
}
