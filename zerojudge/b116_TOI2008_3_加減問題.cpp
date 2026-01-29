// ==================================================
// Problem   : ZeroJudge B116 - TOI2008 3. 加減問題
// URL       : https://zerojudge.tw/ShowProblem?problemid=b116
// ==================================================

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m, n;
    while(cin >> m){
        cin >> n;
        while(m--){
            vector < int > a(n);
            for(int i=0; i<n; i++){
                cin >> a[i];
            }

            int sum_a = 0;
            for(int i=0; i<n; i++){
                sum_a += a[i];
            }

            int k = sum_a / 2;
            vector < int > dp(k+1, 0);
            for(int i=0; i<n; i++){
                for(int j=k; j-a[i]>=0; j--){
                    dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
                }
            }

            // for(int i=0; i<=k; i++){
            //     cout << dp[i] << ' ';
            // }
            // cout << endl;

            if(dp[k]*2==sum_a){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}