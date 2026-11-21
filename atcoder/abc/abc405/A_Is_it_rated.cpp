/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc405_a // Is it rated?
 https://atcoder.jp/contests/abc405/tasks/abc405_a

 AC // C++ 23 (gcc 12.2) // 2 ms // 100.0 pt
 #65630895 // 2025-05-10 20:01:38 +0800
 https://atcoder.jp/contests/abc405/submissions/65630895

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
    int r, x;
    cin >> r >> x;

    if((1600<=r and r<=2999 and x==1) or (1200<=r and r<=2399 and x==2)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
