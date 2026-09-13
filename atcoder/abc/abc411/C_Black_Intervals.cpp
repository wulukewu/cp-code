/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc411_c — Black Intervals
 * Problem URL:    https://atcoder.jp/contests/abc411/tasks/abc411_c
 *
 * Matched result: AC
 * Submission:     #66943820
 * Submission URL: https://atcoder.jp/contests/abc411/submissions/66943820
 * Submitted:      2025-06-21 20:17:36 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        586 ms
 * Points:         350.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-06-21 21:44:43 +0800
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

    int a;
    int ans = 0;
    for(int i=0; i<q; i++){
        cin >> a;
        a--;

        if(arr[a]==0){
            arr[a]=1;
            if(a==0){
                if(arr[a+1]==0){
                    ans++;
                }
            }else if(a==n-1){
                if(arr[a-1]==0){
                    ans++;
                }
            }else{
                if(arr[a-1]==1 and arr[a+1]==1){
                    ans--;
                }else if(arr[a-1]==0 and arr[a+1]==0){
                    ans++;
                }
            }
        }else{
            arr[a]=0;
            if(a==0){
                if(arr[a+1]==0){
                    ans--;
                }
            }else if(a==n-1){
                if(arr[a-1]==0){
                    ans--;
                }
            }else{
                if(arr[a-1]==0 and arr[a+1]==0){
                    ans--;
                }else if(arr[a-1]==1 and arr[a+1]==1){
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}
