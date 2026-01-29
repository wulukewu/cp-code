// ==================================================
// Problem   : ZeroJudge D390 - 00562 - Dividing coins
// URL       : https://zerojudge.tw/ShowProblem?problemid=d390
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector < int > c(n);
        for(int i=0; i<n; i++){
            cin >> c[i];
        }

        int sum_c = 0;
        for(int i=0; i<n; i++){
            sum_c += c[i];
        }

        int k = sum_c / 2;
        vector < int > dp(k+1, 0);
        for(int i=0; i<n; i++){
            for(int j=k; j-c[i]>=0; j--){
                dp[j] = max(dp[j], dp[j-c[i]]+c[i]);
            }
        }

        // for(int i=0; i<=k; i++){
        //     cout << dp[i] << ' ';
        // }
        // cout << endl;

        cout << sum_c - dp[k]*2 << endl;
    }
}