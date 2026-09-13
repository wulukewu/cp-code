/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc399_b — Ranking with Ties
 * Problem URL:    https://atcoder.jp/contests/abc399/tasks/abc399_b
 *
 * Matched result: AC
 * Submission:     #64299241
 * Submission URL: https://atcoder.jp/contests/abc399/submissions/64299241
 * Submitted:      2025-03-29 20:21:34 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         200.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-03-29 22:49:16 +0800
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
    
    int n;
    cin >> n;

    vector < int > arr(n);
    vector < pair < int, int > > brr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        brr[i] = make_pair(arr[i], -1);
    }

    sort(brr.begin(), brr.end());
    reverse(brr.begin(), brr.end());

    int r = 0;
    int rr = 0;
    int m = 101;
    for(int i=0; i<n; i++){
        if(brr[i].first < m){
            if(rr){
                r += rr;
                rr = 0;
            }
            r++;
            brr[i].second = r;
            m = brr[i].first;
        }else if(brr[i].first == m){
            brr[i].second = r;
            rr++;
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << brr[i].first << ' ' << brr[i].second << endl;
    // }

    map < int, int > ans;
    for(int i=0; i<n; i++){
        if(ans.find(brr[i].first) == ans.end()){
            ans.insert(make_pair(brr[i].first, brr[i].second));
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[arr[i]] << endl;
    }


    // vector < int > ans(n, 0);
    // int r = 1;
    // int m, m_idx;
    // bool has_done;
    // while(true){
    //     m = 0;
    //     m_idx = -1;
    //     has_done = true;
    //     for(int i=0; i<n; i++){
    //         if(ans[i]==0){
    //             has_done == false;
    //             if(arr[i]>m){
    //                 m = arr[i];
    //                 m_idx = i;
    //             }
    //         }
    //     }
    //     if(has_done)break;
    //     ans[m_idx] = r;
    //     r++;
    // }

    // for(int i=0; i<n; i++){
    //     cout << ans[i] << endl;
    // }
        
}
