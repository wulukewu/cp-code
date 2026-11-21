/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 2041A // The Bento Box Adventure
 https://codeforces.com/contest/2041/problem/A

 AC // C++20 (GCC 13-64) // 46 ms // 0 B
 #398092763 // 2026-11-11 12:34:16 +0800
 rating 1300 // implementation, sortings
 https://codeforces.com/contest/2041/submission/398092763

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int k = 15,n = 4,t;
    while(n--){
        cin >> t;
        k -= t;
    }
    cout << k << "\n";
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}