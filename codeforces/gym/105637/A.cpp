/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 105637A // Final Price
 https://codeforces.com/gym/105637/problem/A

 AC // C++23 (GCC 14-64, msys2) // 61 ms // 0 B
 #336841664 // 2025-09-04 15:59:06 +0800
 https://codeforces.com/gym/105637/submission/336841664

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0,in;
    while(n--){
        cin >> in;
        ans += in;
    }
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}