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