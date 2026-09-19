#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if(b-a == c-b) cout << "secret " << b-a << endl;
    else cout << "not secret\n";
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}