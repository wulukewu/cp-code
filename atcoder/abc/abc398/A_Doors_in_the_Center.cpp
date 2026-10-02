/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc398_a // Doors in the Center
 https://atcoder.jp/contests/abc398/tasks/abc398_a

 AC // C++ 23 (gcc 12.2) // 1 ms // 100.0 pt
 #64027595 // 2025-03-22 20:02:38 +0800
 https://atcoder.jp/contests/abc398/submissions/64027595

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

    if(n%2){
        for(int i=0; i<n; i++){
            if(i==n/2){
                cout << '=';
            }else{
                cout << '-';
            }
        }
    }else{
        for(int i=0; i<n; i++){
            if(i==n/2 || i==n/2-1){
                cout << '=';
            }else{
                cout << '-';
            }
        }
    }
}
