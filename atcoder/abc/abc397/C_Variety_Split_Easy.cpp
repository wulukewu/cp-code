/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc397_c // Variety Split Easy
 https://atcoder.jp/contests/abc397/tasks/abc397_c

 AC // C++ 23 (gcc 12.2) // 61 ms // 350.0 pt
 #63796791 // 2025-03-15 20:28:14 +0800
 https://atcoder.jp/contests/abc397/submissions/63796791

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

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // map < int, int > a;
    // map < int, int > b;
    // int ans = 0;
    // for(int i=0; i<n; i++){
    //     if(b.find(arr[i])==b.end()){
    //         b.insert(make_pair(arr[i], 1));
    //     }else{
    //         b[i]++;
    //     }
    // }
    // for(int i=0; i<b.size(); i++){
    //     cout << b[i] << ' ';
    // }cout << endl;

    vector < int > a(3e5, 0);
    vector < int > b(3e5, 0);
    for(int i=0; i<n; i++){
        b[arr[i]-1]++;
    }
    
    int x=0;
    for(int i=0; i<3e5; i++){
        if(b[i]>0) x++;
    }
    // cout << x << endl;
    
    int ans = 0;
    for(int i=0; i<n; i++){
        if(b[arr[i]-1]==1) x--;
        b[arr[i]-1]--;

        if(a[arr[i]-1]==0) x++;
        a[arr[i]-1]++;

        ans = max(ans, x);
    }

    cout << ans;

}
