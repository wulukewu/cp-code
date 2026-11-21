/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc401_b // Unauthorized
 https://atcoder.jp/contests/abc401/tasks/abc401_b

 AC // C++ 23 (gcc 12.2) // 1 ms // 200.0 pt
 #65034572 // 2025-04-19 21:21:56 +0800
 https://atcoder.jp/contests/abc401/submissions/65034572

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

    int m = 0;
    int ans = 0;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        
        if(s=="login"){
            m = 1;
        }else if(s=="logout"){
            m = 0;
        }else if(s=="private"){
            if(m==0){
                ans++;
            }
        }
    }

    cout << ans;
}
