// ==================================================
// Problem   : 104997C - Unknown
// URL       : https://codeforces.com/contest/104997/problem/C
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector < vector < int > > dp(n+1, vector < int > (m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> dp[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int x1, y1, x2 ,y2;
    for(int i=0; i<k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << endl;
    }
}