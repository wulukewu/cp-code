// ==================================================
// Problem   : 104997H - Unknown
// URL       : https://codeforces.com/contest/104997/problem/H
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector < vector < int > > dp(1002, vector < int > (1002, 0));
    int x1, y1, x2, y2;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        dp[x1][y1]++;
        dp[x2][y1]--;
        dp[x1][y2]--;
        dp[x2][y2]++;
    }

    for(int j=1; j<1002; j++){
        dp[0][j] += dp[0][j-1];
    }

    for(int i=1; i<1002; i++){
        dp[i][0] += dp[i-1][0];
    }

    for(int i=1; i<1002; i++){
        for(int j=1; j<1002; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            if(dp[i][j]==k) ans++;
        }
    }

    cout << ans;
}