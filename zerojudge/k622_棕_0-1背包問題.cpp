#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector < int > w(n);
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    vector < int > c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    int sum_w = 0;
    for(int i=0; i<n; i++){
        sum_w += w[i];
    }

    vector < int > dp(k+1, 0);
    for(int i=0; i<n; i++){
        for(int j=k; j-w[i]>=0; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
        }
    }

    // for(int i=0; i<=k; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    cout << dp[k];

    /*
    // if(k>=sum_w){
    //     int sum_c = 0;
    //     for(int i=0; i<n; i++){
    //         sum_c += c[i];
    //     }
    //     cout << sum_c;
    // }else{

    vector < vector < int > > dp(n, vector < int > (k+1, -1));

    for(int i=0; i<n; i++){
        dp[i][0] = 0;
    }

    for(int j=0; j<=k; j++){
        if(j>=w[0]){
            dp[0][j] = c[0];
        }else{
            dp[0][j] = 0;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+c[i]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=k; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // cout << dp[n-1][k];

    // }
    */
}
