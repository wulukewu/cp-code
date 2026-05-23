#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=a; i<b; i++)

signed main(){
    int t;
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        int n, k;
        cin >> n >> k;
        if(n%2==1 or k==0){
            cout << "Case " << tt << ": " << 0 << endl;
            continue;
        }

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k, vector<int>(n+1, 0)));
        dp[1][1%k][1] = 1;
        FOR(i, 1, n){
            FOR(j, 0, k){
                FOR(l, 0, n+1){
                    dp[i+1][(j*2)%k][l] += dp[i][j][l];
                    dp[i+1][(j*2+1)%k][l+1] += dp[i][j][l];
                }
            }
        }
        
        // FOR(i, 0, n+1){
        //     FOR(j, 0, k){
        //         FOR(l, 0, n+2){
        //             cout << dp[i][j][l] << ' ';
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }

        cout << "Case " << tt << ": " << dp[n][0][n/2] << endl;
        
        // n /= 2;
        // vector<vector<int>>dp(n+1, vector<int>(k, 0));
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(k, vector<int>(2*n+1, 0)));
        // dp[0][0][0] = 1;
        // FOR(i, 1, n+1){
        //     FOR(j, 0, k){
        //         FOR(l, 0, 2*n+1){
        //             // 01
        //             int a = (j*4+1) % k;
        //             dp[i][a][l+1] += dp[i-1][j][l];
        //             // 10
        //             int b = (j*4+2) % k;
        //             dp[i][b][l+1] += dp[i-1][j][l];
        //             // 00
        //             int c = (j*4) % k;
        //             dp[i][c][l+1] += dp[i-1][j][l];
        //             // 11
        //             int d = (j*4+3) % k;
        //             dp[i][d][l+2] += dp[i-1][j][l];
        //         }
        //         // // 01
        //         // int a = (j+101) % k;
        //         // dp[i][a] += dp[i-1][j];
        //         // // 10
        //         // int b = (j+110) % k;
        //         // dp[i][b] += dp[i-1][j];
        //         // // 00
        //         // int c = (j+100) % k;
        //         // dp[i][c] += dp[i-1][j];
        //         // // 11
        //         // int d = (j+111) % k;
        //         // dp[i][d] += dp[i-1][j];
        //     }
        // }
    }
}