/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc397_d // Cubes
 https://atcoder.jp/contests/abc397/tasks/abc397_d

 WA // C++ 23 (gcc 12.2) // 191 ms // 0.0 pt
 #63831121 // 2025-03-15 21:18:10 +0800 // 4 attempts
 https://atcoder.jp/contests/abc397/submissions/63831121

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
    
    int n;
    cin >> n;

    int m = 1e7;

    vector < int > arr(m);
    for(int i=0; i<m; i++){
        // arr[i] = pow((i+1), 3);
        arr[i] = (i+1)*(i+1)*(i+1);
    }

    int x=0;
    int goal;
    bool minus_one = false;
    for(int y=0; y<m; y++){
        goal = n + arr[y];
        while(arr[x]<goal){
            x++;
            if(x>=m){
                // cout << -1;
                minus_one = true;
                break;
            }
        }
        if(arr[x]==goal){
            cout << x+1 << ' ' << y+1;
            break;
        }
    }

    if(minus_one){
        cout << -1;
    }
}
