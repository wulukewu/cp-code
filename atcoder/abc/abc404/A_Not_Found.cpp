/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc404_a — Not Found
 * Problem URL:    https://atcoder.jp/contests/abc404/tasks/abc404_a
 *
 * Matched result: AC
 * Submission:     #65426425
 * Submission URL: https://atcoder.jp/contests/abc404/submissions/65426425
 * Submitted:      2025-05-03 20:05:41 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         100.0
 * Submissions:    1 total / 1 accepted
 * File commit:    2025-05-03 22:26:32 +0800
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
    string s;
    cin >> s;

    int n = s.size();

    char c = 'a';
    for(int i=0; i<26; i++){
        // cout << c << endl;
        bool det = true;
        for(int j=0; j<n; j++){
            if(c==s[j]){
                det = false;
                break;
            }
        }
        if(det){
            cout << c;
            break;
        }
        c++;
    }
}
