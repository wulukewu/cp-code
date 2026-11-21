/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc400_c // 2^a b^2
 https://atcoder.jp/contests/abc400/tasks/abc400_c

 AC // C++ 23 (gcc 12.2) // 1915 ms // 350.0 pt
 #64516757 // 2025-04-05 20:13:50 +0800
 https://atcoder.jp/contests/abc400/submissions/64516757

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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int ans = 0;
    int a, b;
    for(int i=1; i<=(int)sqrt(n); i++){
        if(i%2==0)continue;
        // cout << i << endl;
        a = i * i;
        b = n / a;
        // cout << a << ' ' << b << endl;
        b /= 2;
        while(b>0){
            ans++;
            b /= 2;
        }
        // cout << ans << endl;
    }

    cout << ans;
}
