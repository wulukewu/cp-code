/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 2041E // Beautiful Array
 https://codeforces.com/contest/2041/problem/E

 AC // C++20 (GCC 13-64) // 46 ms // 0 B
 #398093440 // 2026-11-11 12:49:14 +0800
 rating 1200 // constructive algorithms, math
 https://codeforces.com/contest/2041/submission/398093440

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
#define FOR(i, a, b) for(int i = a; i < b; i++)
template<typename T>
void print(T a){
    for(auto u:a){
        cout << u << ' ';
    }
    
}

void solve(){
    int a,b;
    cin >> a >> b;
    if(a == b){
        cout << "1\n" << a << endl;
    }
    else{
        cout << 3 << endl;
        int s = a * 3;
        if(s - b * 2 < b){
            cout << s - b * 2 << " " << b << " " << b << endl;
        }
        else{
            cout << b << " " << b << " " << s - b * 2 << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}