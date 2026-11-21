/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 106084L // Stapler
 https://codeforces.com/gym/106084/problem/L

 AC // C++20 (GCC 13-64) // 31 ms // 0 B
 #390728434 // 2026-09-14 21:58:54 +0800 // 8 attempts
 https://codeforces.com/gym/106084/submission/390728434

 cp-code:submission-metadata
*/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long

void solve(){
    int xl, yl, xr, yr;
    cin >> xl >> yl >> xr >> yr;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(xl<=x1 and x1<=xr and yl<=y1 and y1<=yr){
        cout << "STOP" << endl;
        return;
    }
    if(xl<=x2 and x2<=xr and yl<=y2 and y2<=yr){
        cout << "STOP" << endl;
        return;
    }
    
    if(x1==x2){
        if(min(y1, y2)<=yr and max(y1, y2)>=yl and xl<=x1 and x1<=xr){
            cout << "STOP" << endl;
        }else{
            cout << "OK" << endl;
        }
        return;
    }
    if(y1==y2){
        if(min(x1, x2)<=xr and max(x1, x2)>=xl and yl<=y1 and y1<=yr){
            cout << "STOP" << endl;
        }else{
            cout << "OK" << endl;
        }
        return;
    }

    double val_yl = (double)(y2-y1)/(x2-x1)*(xl-x1) + y1;
    if(min(y1, y2)<=val_yl and val_yl<=max(y1, y2) and yl<=val_yl and val_yl<=yr){
        cout << "STOP" << endl;
        return;
    }
    double val_yr = (double)(y2-y1)/(x2-x1)*(xr-x1) + y1;
    if(min(y1, y2)<=val_yr and val_yr<=max(y1, y2) and yl<=val_yr and val_yr<=yr){
        cout << "STOP" << endl;
        return;
    }
    double val_xl = (double)(x2-x1)/(y2-y1)*(yl-y1) + x1;
    if(min(x1, x2)<=val_xl and val_xl<=max(x1, x2) and xl<=val_xl and val_xl<=xr){
        cout << "STOP" << endl;
        return;
    }
    double val_xr = (double)(x2-x1)/(y2-y1)*(yr-y1) + x1;
    if(min(x1, x2)<=val_xr and val_xr<=max(x1, x2) and xl<=val_xr and val_xr<=xr){
        cout << "STOP" << endl;
        return;
    }

    // int val_yl = (y2-y1)*(xl-x1) + y1*(x2-x1);
    // if(min(y1, y2)*(x2-x1)<=val_yl and val_yl<=max(y1, y2)*(x2-x1) and yl*(x2-x1)<=val_yl and val_yl<=yr*(x2-x1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_yr = (y2-y1)*(xr-x1) + y1*(x2-x1);
    // if(min(y1, y2)*(x2-x1)<=val_yr and val_yr<=max(y1, y2)*(x2-x1) and yl*(x2-x1)<=val_yr and val_yr<=yr*(x2-x1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xl = (x2-x1)*(yl-y1) + x1*(y2-y1);
    // if(min(x1, x2)*(y2-y1)<=val_xl and val_xl<=max(x1, x2)*(y2-y1) and xl*(y2-y1)<=val_xl and val_xl<=xr*(y2-y1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xr = (x2-x1)*(yr-y1) + x1*(y2-y1);
    // if(min(x1, x2)*(y2-y1)<=val_xr and val_xr<=max(x1, x2)*(y2-y1) and xl*(y2-y1)<=val_xr and val_xr<=xr*(y2-y1)){
    //     cout << "STOP" << endl;
    //     return;
    // }

    // int val_yl = (y2-y1)*(xl-x1) + y1*(x2-x1);
    // if(min(y1, y2)*(x2-x1)<=val_yl and val_yl<=max(y1, y2)*(x2-x1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_yr = (y2-y1)*(xr-x1) + y1*(x2-x1);
    // if(min(y1, y2)*(x2-x1)<=val_yr and val_yr<=max(y1, y2)*(x2-x1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xl = (x2-x1)*(yl-y1) + x1*(y2-y1);
    // if(min(x1, x2)*(y2-y1)<=val_xl and val_xl<=max(x1, x2)*(y2-y1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xr = (x2-x1)*(yr-y1) + x1*(y2-y1);
    // if(min(x1, x2)*(y2-y1)<=val_xr and val_xr<=max(x1, x2)*(y2-y1)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // double val_yl = (double)(y2-y1)/(x2-x1) * (xl-x1) + y1;
    // if(min(y1, y2)<=val_yl and val_yl<=max(y1, y2)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // double val_yr = (double)(y2-y1)/(x2-x1) * (xr-x1) + y1;
    // if(min(y1, y2)<=val_yr and val_yr<=max(y1, y2)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // double val_xl = (double)(x2-x1)/(y2-y1) * (yl-y1) + x1;
    // if(min(x1, x2)<=val_xl and val_xl<=max(x1, x2)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // double val_xr = (double)(x2-x1)/(y2-y1) * (yr-y1) + x1;
    // if(min(x1, x2)<=val_xr and val_xr<=max(x1, x2)){
    //     cout << "STOP" << endl;
    //     return;
    // }
    
    // int val_yl = (double)(y2-y1)/(x2-x1) * (xl-x1) + y1;
    // if(yl<=val_yl and val_yl<=yr){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_yr = (double)(y2-y1)/(x2-x1) * (xr-x1) + y1;
    // if(yl<=val_yr and val_yr<=yr){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xl = (double)(x2-x1)/(y2-y1) * (yl-y1) + x1;
    // if(xl<=val_xl and val_xl<=xr){
    //     cout << "STOP" << endl;
    //     return;
    // }
    // int val_xr = (double)(x2-x1)/(y2-y1) * (yr-y1) + x1;
    // if(xl<=val_xr and val_xr<=xr){
    //     cout << "STOP" << endl;
    //     return;
    // }
    cout << "OK" << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}