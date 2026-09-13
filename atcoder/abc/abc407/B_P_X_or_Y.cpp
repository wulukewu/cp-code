/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc407_b — P(X or Y)
 * Problem URL:    https://atcoder.jp/contests/abc407/tasks/abc407_b
 *
 * Matched result: AC
 * Submission:     #66099599
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66099599
 * Submitted:      2025-05-24 20:16:48 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         250.0
 * Submissions:    2 total / 1 accepted
 * File commit:    2025-05-26 10:46:51 +0800
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
    int x, y;
    cin >> x >> y;

    set < pair < int, int > > s;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            if(i+j>=x or abs(i-j)>=y){
                if(s.find(make_pair(i, j))==s.end()){
                    s.insert(make_pair(i, j));
                }
            }
        }
    }

    // for(auto i: s){
    //     cout << i.first << ' ' << i.second << endl;
    // }

    double ans = (double) s.size() / 36;
    // cout << ans;
    printf("%.12f", ans);
}
