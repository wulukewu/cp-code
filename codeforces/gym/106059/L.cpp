/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 106059L // Lantern Festival
 https://codeforces.com/gym/106059/problem/L

 AC // C++23 (GCC 14-64, msys2) // 62 ms // 0 B
 #339072289 // 2025-09-17 20:19:23 +0800
 https://codeforces.com/gym/106059/submission/339072289

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int x;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==1) ans++;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}