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