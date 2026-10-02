/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 106084A // Take It or Double It
 https://codeforces.com/gym/106084/problem/A

 AC // C++20 (GCC 13-64) // 31 ms // 100.0 KiB
 #390710248 // 2026-09-14 19:05:44 +0800
 https://codeforces.com/gym/106084/submission/390710248

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    int a,b;
    cin >> a >> b;
    if(a*2 > b) cout << "take it\n";
    else cout << "double it\n";
    // cout << a << endl;

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}