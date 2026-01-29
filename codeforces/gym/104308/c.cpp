// ==================================================
// Problem   : 104308C - Unknown
// URL       : https://codeforces.com/contest/104308/problem/C
// ==================================================

#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=n-1; i>=0; i-=2){
        ans += arr[i];
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