/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc413_b — cat 2
 * Problem URL:    https://atcoder.jp/contests/abc413/tasks/abc413_b
 *
 * Matched result: AC
 * Submission:     #67303650
 * Submission URL: https://atcoder.jp/contests/abc413/submissions/67303650
 * Submitted:      2025-07-05 20:06:30 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        5 ms
 * Points:         200.0
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
    int n;
    cin >> n;

    vector < string > s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    set < string > st;
    string t;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            t = s[i] + s[j];
            if(st.find(t) == st.end()){
                st.insert(t);
            }
            
            t = s[j] + s[i];
            if(st.find(t) == st.end()){
                st.insert(t);
            }
        }
    }

    cout << st.size();
}
