/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc398_c — Uniqueness
 * Problem URL:    https://atcoder.jp/contests/abc398/tasks/abc398_c
 *
 * Matched result: AC
 * Submission:     #64073137
 * Submission URL: https://atcoder.jp/contests/abc398/submissions/64073137
 * Submitted:      2025-03-22 20:44:32 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        507 ms
 * Points:         300.0
 * Submissions:    4 total / 1 accepted
 * File commit:    2025-03-22 22:07:04 +0800
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

    map < int, int > arr;
    map < int, int > brr;

    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        if(arr.find(a) == arr.end()){
            arr[a] = i+1;
            brr[a] = 1;
        }else{
            arr[a] = max(arr[a], i+1);
            brr[a]++;
        }
    }

    int ans = -1;
    int ans_first = -1;
    for(auto i: arr){
        // cout << i.first << ' ' << i.second << endl;
        if(brr[i.first]==1){
            if(i.first > ans_first){
                ans = i.second;
                ans_first = i.first;
            }
        }
    }

    cout << ans;

}
