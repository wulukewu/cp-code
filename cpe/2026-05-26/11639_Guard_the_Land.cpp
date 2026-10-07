/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 UVa // 11639 // Guard the Land
 https://onlinejudge.org/external/116/11639.pdf

 problem metadata: uHunt // time limit 1000 ms

 cp-code:submission-metadata
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=a; i<b; i++)
signed main(){
    int n;
    cin >> n;
    FOR(nn, 1, n+1){
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int a = (x2-x1)*(y2-y1);
        int b = (x4-x3)*(y4-y3);
        int w = max(min(x2, x4)-max(x1, x3), 0ll);
        int h = max(min(y2, y4)-max(y1, y3), 0ll);
        int ans1 = w*h;
        int ans2 = a+b-2*ans1;
        int ans3 = 100*100-ans1-ans2;
        cout << "Night " << nn << ": ";
        cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    }
}