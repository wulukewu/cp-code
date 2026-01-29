// ==================================================
// Problem   : ABC413_E - Reverse 2^i
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc413/tasks/abc413_e
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

signed solve(){
    int n;
    cin >> n;
    
    int m = 1;
    for(int i=0; i<n; i++){
        m *= 2;
    }

    vector < int > p(m);
    for(int i=0; i<m; i++){
        cin >> p[i];
    }

    for(int i=0; i<m; i++){
        cout << p[i] << ' ';
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
