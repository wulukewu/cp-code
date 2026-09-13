/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc403_b — Four Hidden
 * Problem URL:    https://atcoder.jp/contests/abc403/tasks/abc403_b
 *
 * Matched result: AC
 * Submission:     #65247666
 * Submission URL: https://atcoder.jp/contests/abc403/submissions/65247666
 * Submitted:      2025-04-27 20:08:41 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        1 ms
 * Points:         250.0
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
    
    string t, u;
    cin >> t >> u;

    int nt = t.size();
    int nu = u.size();

    for(int i=0; i<nt-nu+1; i++){
        bool det = false;
        for(int j=0; j<nu; j++){
            if(t[i+j]==u[j] or t[i+j]=='?'){
                continue;
            }else{
                det = true;
            }
        }
        if(!det){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
