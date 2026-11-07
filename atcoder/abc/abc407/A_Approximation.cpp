/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc407_a // Approximation
 https://atcoder.jp/contests/abc407/tasks/abc407_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 150.0 pt
 #66098063 // 2025-05-24 20:15:02 +0800 // 3 attempts
 https://atcoder.jp/contests/abc407/submissions/66098063

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
    int a, b;
    cin >> a >> b;

    int c = a/b;
    if(b-(a%b)>(a%b)){}
    else c++;
    cout << c;
}
