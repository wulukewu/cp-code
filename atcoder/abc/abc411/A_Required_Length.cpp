/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc411_a // Required Length
 https://atcoder.jp/contests/abc411/tasks/abc411_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 100.0 pt
 #66925300 // 2025-06-21 20:01:02 +0800
 https://atcoder.jp/contests/abc411/submissions/66925300

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
    string p;
    cin >> p;

    int l;
    cin >> l;

    if(p.size()>=l){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
