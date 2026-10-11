/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc410_a // G1
 https://atcoder.jp/contests/abc410/tasks/abc410_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 100.0 pt
 #66721611 // 2025-06-14 20:02:56 +0800
 https://atcoder.jp/contests/abc410/submissions/66721611

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
    int n;
    cin >> n;

    vector < int > a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int k;
    cin >> k;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(k<=a[i]) ans++;
    }

    cout << ans;
}
