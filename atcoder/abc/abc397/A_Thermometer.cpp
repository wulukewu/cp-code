/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc397_a // Thermometer
 https://atcoder.jp/contests/abc397/tasks/abc397_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 100.0 pt
 #63762235 // 2025-03-15 20:01:57 +0800
 https://atcoder.jp/contests/abc397/submissions/63762235

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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    float x;
    cin >> x;

    if(x >= 38){
        cout << 1;
    }else if(x >= 37.5){
        cout << 2;
    }else{
        cout << 3;
    }

}
