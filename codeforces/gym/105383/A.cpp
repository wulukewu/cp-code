/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 105383A // Animal Farm
 https://codeforces.com/gym/105383/problem/A

 AC // C++23 (GCC 14-64, msys2) // 280 ms // 200.0 KiB
 #339440601 // 2025-09-20 07:00:28 +0800
 https://codeforces.com/gym/105383/submission/339440601

 cp-code:submission-metadata
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < string > a(n);
    vector < int > b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int m = 0;
    for(int i=0; i<n; i++){
        if(a[i]=="pig"){
            m = max(m, b[i]);
        }
    }

    int ans = m;
    for(int i=0; i<n; i++){
        if(a[i]!="pig" and b[i]<m){
            ans += b[i];
        }
    }
    cout << ans << endl;
}