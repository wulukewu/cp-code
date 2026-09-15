#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    // cout << n << endl;
    vector< vector<int> > dp(n , vector<int>(n,n+7));
    dp[0][n-1] = 0;
    // cout << dp[0][n-1];
    for(int k = n-1;k>=1;k--){
        for(int l = 0;l+k <= (n-1);l++){
            int r = l+k;
            if(s[l] == s[r]) dp[l+1][r-1] = min(dp[l+1][r-1],dp[l][r]);
            else dp[l+1][r-1] = min(dp[l+1][r-1] , dp[l][r] + 1);
            dp[l+1][r] = min(dp[l+1][r] , dp[l][r] + 1);
            dp[l][r-1] = min(dp[l][r-1] , dp[l][r] + 1);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dp[i][j] << " \t";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ans = n+7;
    for(int l=0;l<=n-1;l++){
        ans = min(ans,dp[l][l]);
        // cout << dp[l][l] << ".";
        if(l+1 <= n-1){
            ans = min(ans,dp[l+1][l]);
            // cout << dp[l][l+1];
        }
        // cout << endl;
    }
    
    cout << ans << endl;
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