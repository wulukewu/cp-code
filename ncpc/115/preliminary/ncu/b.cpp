#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    int n,k;
    cin >> n >> k;
    int eat = 0 , ans = 0;
    for(int i=0;i<n;i++){
        int day = eat/k;
        int c,h;
        cin >> c >> h;
        if(h > day){
            ans++;
            eat += c;
        }
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}