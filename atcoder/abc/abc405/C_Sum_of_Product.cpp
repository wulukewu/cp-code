// ==================================================
// Problem   : ABC405_C - Sum of Product
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc405/tasks/abc405_c
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
    int n;
    cin >> n;

    vector < int > a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector < int > b(n+1, 0);
    for(int i=1; i<=n; i++){
        b[i] = b[i-1] + a[i-1];
    }

    // for(int i=0; i<=n; i++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += a[i] * (b[n]-b[i+1]);
    }

    cout << ans;
}
