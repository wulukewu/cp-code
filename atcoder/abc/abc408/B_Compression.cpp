/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc408_b // Compression
 https://atcoder.jp/contests/abc408/tasks/abc408_b

 AC // C++ 23 (gcc 12.2) // 1 ms // 150.0 pt
 #66312430 // 2025-05-31 20:10:01 +0800
 https://atcoder.jp/contests/abc408/submissions/66312430

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
    int n;
    cin >> n;

    set < int > s;
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        if(s.find(a)==s.end()){
            s.insert(a);
        }
    }

    cout << s.size() << endl;
    for(auto i: s){
        cout << i << ' ';
    }
}
