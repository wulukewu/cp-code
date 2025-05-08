#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    vector < int > w(n);
    vector < int > v(n);
    for(int i=0; i<n; i++){
        cin >> w[i] >> v[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << w[i] << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     cout << v[i] << ' ';
    // }
    // cout << endl;

    vector < vector < int > > dp(n+1, vector < int > (k+1, 0));
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(j<w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
            
            // cout << i << ' ' << j << ' ' << dp[i+1][j] << endl;
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=k; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[n][k];
}
