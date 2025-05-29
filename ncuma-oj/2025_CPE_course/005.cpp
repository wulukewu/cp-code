#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int t=0;
    int a, b;
    while(cin >> a){
        cin >> b;
        if(a==0 and b==0) break;
        t++;

        vector < int > arr(a);
        for(int i=0; i<a; i++){
            cin >> arr[i];
        }
        vector < int > brr(b);
        for(int i=0; i<b; i++){
            cin >> brr[i];
        }

        vector < vector < int > > dp(a+1, vector < int > (b+1, 0));
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(arr[i-1]==brr[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        if(t>1) cout << endl;
        cout << "Twin Towers #" << t << endl << "Number of Tiles : " << dp[a][b] << endl;

    }
}