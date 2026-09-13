/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc413_c — Large Queue
 * Problem URL:    https://atcoder.jp/contests/abc413/tasks/abc413_c
 *
 * Matched result: AC
 * Submission:     #67315420
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67315420
 * Submitted:      2025-07-05 20:19:44 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        192 ms
 * Points:         300.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-07-05 22:19:41 +0800
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
    int q;
    cin >> q;

    queue < pair < int, int > > qu;
    
    int type, c, x, k, ans;
    while(q--){
        cin >> type;
        if(type==1){
            cin >> c >> x;
            qu.push(make_pair(c, x));
        }else{
            cin >> k;
            ans = 0;
            while(k>0){
                if(k>=qu.front().first){
                    k -= qu.front().first;
                    ans += qu.front().first * qu.front().second;
                    // cout << qu.front().first << ' ' << qu.front().second << endl;
                    qu.pop();
                }else{
                    qu.front().first -= k;
                    ans += k * qu.front().second;
                    // cout << k << ' ' << qu.front().second << endl;
                    k = 0;
                }
            }
            cout << ans << endl;
        }
    }
}
