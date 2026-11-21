/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 105637B // Flower Festival
 https://codeforces.com/gym/105637/problem/B

 AC // C++23 (GCC 14-64, msys2) // 46 ms // 0 B
 #336844508 // 2025-09-04 16:32:24 +0800 // 4 attempts
 https://codeforces.com/gym/105637/submission/336844508

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, f;
    cin >> n >> f;

    int ansidx = 1;
    double anssecond = -1;
    for(int i = 1; i <= n; i++){
        double time;
        int where, speed;

        cin >> where >> speed;
        time = (f - where) / speed;

        if(anssecond == -1 or time < anssecond){
            ansidx = i;
            anssecond = time;
        }
    }

    cout << ansidx << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}