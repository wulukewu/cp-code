/* cp-code:submission-metadata
 * Generated on the annotated branch. Do not edit manually.
 * Platform:       AtCoder
 * Problem:        abc407_d — Domino Covering XOR
 * Problem URL:    https://atcoder.jp/contests/abc407/tasks/abc407_d
 *
 * Matched result: AC
 * Submission:     #66133313
 * Submission URL: https://atcoder.jp/contests/abc407/submissions/66133313
 * Submitted:      2025-05-24 21:36:52 +0800
 * Language:       C++ 23 (gcc 12.2)
 * Runtime:        233 ms
 * Points:         425.0
 * Submissions:    4 total / 1 accepted
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

vector < vector < int > > arr;
int h, w;
vector < vector < int > > v;
set < vector < vector < int > > > vv;
int sum;
set < int > s;

void dfs(){
    if(vv.find(v) != vv.end()) return;
    vv.insert(v);

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(i+1<h and v[i][j]==0 and v[i+1][j]==0){
                v[i][j] = 1;
                v[i+1][j] = 1;
                sum ^= arr[i][j];
                sum ^= arr[i+1][j];
                s.insert(sum);
                dfs();
                sum ^= arr[i][j];
                sum ^= arr[i+1][j];
                v[i][j] = 0;
                v[i+1][j] = 0;
            }
            if(j+1<w and v[i][j]==0 and v[i][j+1]==0){
                v[i][j] = 1;
                v[i][j+1] = 1;
                sum ^= arr[i][j];
                sum ^= arr[i][j+1];
                s.insert(sum);
                dfs();
                sum ^= arr[i][j];
                sum ^= arr[i][j+1];
                v[i][j] = 0;
                v[i][j+1] = 0;
            }
        }
    }
}

signed main() {
    cin >> h >> w;

    sum = 0;
    arr = vector < vector < int > >(h, vector < int > (w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> arr[i][j];
            sum ^= arr[i][j];
        }
    }
    s.insert(sum);

    v = vector < vector < int > > (h, vector < int > (w, 0));

    dfs();

    int ans = 0;
    for(auto x: s){
        // cout << x << endl;
        ans = max(ans, x);
    }

    cout << ans;
}
