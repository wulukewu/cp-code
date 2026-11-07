/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc409_c // Equilateral Triangle
 https://atcoder.jp/contests/abc409/tasks/abc409_c

 AC // C++ 23 (gcc 12.2) // 56 ms // 300.0 pt
 #66576573 // 2025-06-07 21:33:46 +0800 // 2 attempts
 https://atcoder.jp/contests/abc409/submissions/66576573

 cp-code:submission-metadata
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
    int n, l;
    cin >> n >> l;

    vector < int > a(n);
    a[0] = 0;
    for(int i=1; i<n; i++){
        cin >> a[i];
    }

    if(l % 3 != 0){
        cout << 0;
        return 0;
    }

    for(int i=1; i<n; i++){
        a[i] += a[i-1];
        a[i] %= l;
    }

    // for(int i=0; i<n; i++){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;

    vector < int > b(l, 0);
    for(int i=0; i<n; i++){
        b[a[i]]++;
    }

    // for(int i=0; i<l; i++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;

    int ans = 0;
    for(int i=0; i<l/3; i++){
        int b1 = i;
        int b2 = i+l/3;
        int b3 = i+2*l/3;
        int c = b[b1] * b[b2] * b[b3];
        // cout << b[b1] * b[b2] * b[b3] << endl;
        ans += c;
    }
    cout << ans;
}
