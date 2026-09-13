/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc412_b — Precondition
 * Problem URL:    https://atcoder.jp/contests/abc412/tasks/abc412_b
 *
 * Matched result: AC
 * Submission:     #67127213
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67127213
 * Submitted:      2025-06-28 20:07:07 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         200.0
 * Submissions:    2 total / 1 accepted
 * File commit:    2025-06-28 21:46:58 +0800
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
    string s, t;
    cin >> s >> t;

    set < char > st;
    for(int i=0; i<t.size(); i++){
        if(st.find(t[i])==st.end()){
            st.insert(t[i]);
        }
    }

    bool det = true;
    for(int i=1; i<s.size(); i++){
        if('A'<=s[i] and s[i]<='Z'){
            if(st.find(s[i-1])==st.end()){
                det = false;
                break;
            }
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
