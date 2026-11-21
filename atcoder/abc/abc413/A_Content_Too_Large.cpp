/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc413_a // Content Too Large
 https://atcoder.jp/contests/abc413/tasks/abc413_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 100.0 pt
 #67294683 // 2025-07-05 20:01:38 +0800
 https://atcoder.jp/contests/abc413/submissions/67294683

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
    int n, m;
    cin >> n >> m;

    int a;
    int b = 0;
    for(int i=0; i<n; i++){
        cin >> a;
        b += a;
    }

    if(b<=m){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
