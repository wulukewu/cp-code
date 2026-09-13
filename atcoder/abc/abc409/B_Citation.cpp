/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc409_b — Citation
 * Problem URL:    https://atcoder.jp/contests/abc409/tasks/abc409_b
 *
 * Matched result: AC
 * Submission:     #66569618
 * Submission URL: https://atcoder.jp/contests/abc409/submissions/66569618
 * Submitted:      2025-06-07 21:18:58 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         200.0
 * Submissions:    3 total / 1 accepted
 * File commit:    2025-06-07 21:42:09 +0800
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

    vector < int > a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    map < int, int > mp;
    for(int i=0; i<n; i++){
        if(mp.find(a[i])==mp.end()){
            mp.insert(make_pair(a[i], 1));
        }else{
            mp[a[i]]++;
        }
    }

    // int ans = 0;
    // for(auto i: mp){
    //     // cout << i.first << ' ' << i.second << endl;
    //     if(n >= i.first){
    //         ans = i.first;
    //     }
    //     n -= i.second;
    // }

    // cout << ans;

    int ans = 0;
    for(int i=0; i<=100; i++){
        int c = 0;
        for(auto j: mp){
            if(j.first >= i) c += j.second;
        }
        if(c >= i){
            ans = i;
        }
    }
    cout << ans;
}
