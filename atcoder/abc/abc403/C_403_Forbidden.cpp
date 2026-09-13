/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc403_c — 403 Forbidden
 * Problem URL:    https://atcoder.jp/contests/abc403/tasks/abc403_c
 *
 * Matched result: AC
 * Submission:     #65252827
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65252827
 * Submitted:      2025-04-27 20:15:29 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        208 ms
 * Points:         300.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-04-27 21:42:22 +0800
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
    
    int n, m, q;
    cin >> n >> m >> q;

    vector < set < int > > arr(n);
    vector < int > brr(n, 0);
    int a, x, y;
    while(q--){
        cin >> a;
        if(a==1){
            cin >> x >> y;
            if(arr[x-1].find(y) == arr[x-1].end()){
                arr[x-1].insert(y);
            }
        }else if(a==2){
            cin >> x;
            brr[x-1] = 1;
        }else{
            cin >> x >> y;
            if(arr[x-1].find(y) != arr[x-1].end() or brr[x-1]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
