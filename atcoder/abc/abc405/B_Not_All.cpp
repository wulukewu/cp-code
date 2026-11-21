/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc405_b // Not All
 https://atcoder.jp/contests/abc405/tasks/abc405_b

 AC // C++ 23 (gcc 12.2) // 1 ms // 200.0 pt
 #65641893 // 2025-05-10 20:06:34 +0800
 https://atcoder.jp/contests/abc405/submissions/65641893

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
    int n, m;
    cin >> n >> m;

    vector < int > a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector < int > b(m, 0);
    for(int i=0; i<n; i++){
        b[a[i]-1]++;
    }

    bool det = false;
    for(int i=0; i<m; i++){
        if(b[i]==0){
            det = true;
            break;
        }
    }

    if(det){
        cout << 0;
        return 0;
    }

    int ans = 0;
    for(int i=n-1; i>=0; i--){
        ans++;
        b[a[i]-1]--;
        if(b[a[i]-1]==0){
            break;
        }
    }

    cout << ans;
}
