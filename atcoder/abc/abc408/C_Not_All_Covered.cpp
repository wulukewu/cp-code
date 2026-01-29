// ==================================================
// Problem   : ABC408_C - Not All Covered
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc408/tasks/abc408_c
// ==================================================

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
    int n, m;
    cin >> n >> m;
    
    vector < int > arr(n+1, 0);
    int l, r;
    for(int i=0; i<m; i++){
        cin >> l >> r;
        arr[l-1]++;
        arr[r]--;
    }

    // for(int i=0; i<n+1; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    int c = 0;
    int ans = 1e6;
    for(int i=0; i<n; i++){
        c += arr[i];
        // cout << c << ' ';
        ans = min(ans, c);
        // if(c>0){
        //     ans = min(ans, c);
        // }else{
        //     ans = 0;
        // }
    }
    // cout << endl;

    cout << ans;
}
