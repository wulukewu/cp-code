/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 CODEFORCES // 2041B // Bowling Frame
 https://codeforces.com/contest/2041/problem/B

 AC // C++20 (GCC 13-64) // 31 ms // 0 B
 #398093118 // 2026-11-11 12:41:42 +0800
 rating 1200 // binary search, brute force, math
 https://codeforces.com/contest/2041/submission/398093118

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
    int w, b;
    cin >> w >> b;
    int n = w+b;
    int l = 1, r = n;
    int ans = 0;
    while(l<=r){
        int m = l+(r-l)/2;
        int m2 = m*(m+1)/2;
        if(m2<=n){
            l = m+1;
            ans = m;
        }else{
            r = m-1;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}