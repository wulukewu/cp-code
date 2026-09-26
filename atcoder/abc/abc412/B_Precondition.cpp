/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 ATCODER // abc412_b // Precondition
 https://atcoder.jp/contests/abc412/tasks/abc412_b

 AC // C++ 23 (gcc 12.2) // 1 ms // 200.0 pt
 #67127213 // 2025-06-28 20:07:07 +0800 // 2 attempts
 https://atcoder.jp/contests/abc412/submissions/67127213

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
    string s, t;
    cin >> s >> t;

    set < char > st;
    for(int i=0; i<t.size(); i++){
        if(st.find(t[i])==st.end()){
            st.insert(t[i]);
        }
    }

    bool det = true;
    for(int i=1; i<s.size(); i++){
        if('A'<=s[i] and s[i]<='Z'){
            if(st.find(s[i-1])==st.end()){
                det = false;
                break;
            }
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
