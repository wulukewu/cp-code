/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc397_b // Ticket Gate Log
 https://atcoder.jp/contests/abc397/tasks/abc397_b

 AC // C++ 23 (gcc 12.2) // 1 ms // 250.0 pt
 #63772113 // 2025-03-15 20:06:47 +0800
 https://atcoder.jp/contests/abc397/submissions/63772113

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
    
    string s;
    cin >> s;

    int n=s.size();
    int ans = 0;
    char last = 'o';
    for(int i=0; i<n; i++){
        if(s[i]==last){
            ans++;
        }
        last = s[i];
    }
    if(last=='i'){
        ans++;
    }

    cout << ans;
}
