// ==================================================
// Problem   : ZeroJudge B184 - 5. 裝貨櫃問題
// URL       : https://zerojudge.tw/ShowProblem?problemid=b184
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k = 100;
    int n;
    while(cin >> n){
        vector < int > v(n);
        vector < int > c(n);
        for(int i=0; i<n; i++){
            cin >> v[i] >> c[i];
        }

        vector < vector < int > > dp(n, vector < int > (k+1, -1));

        for(int i=0; i<n; i++){
            dp[i][0] = 0;
        }
        for(int j=0; j<=k; j++){
            if(j>=v[0]){
                dp[0][j] = c[0];
            }else{
                dp[0][j] = 0;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                if(j>=v[i]){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+c[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cout << dp[n-1][k] << endl;
    }
}