// ==================================================
// Problem   : CPE 357 - Let Me Count The Ways
// URL       : https://onlinejudge.org/external/3/357.pdf
// ==================================================

#include <iostream>
#include <vector>
#define int long long

using namespace std;

signed main(){
    vector < int > dp(3e4+1, 1);
    int c[4] = {5, 10, 25, 50};

    for(int i=0; i<4; i++){
        for(int j=0; j<3e4+1; j++){
            if(j-c[i]>=0){
                dp[j] += dp[j-c[i]];
            }
        }
    }

    // for(int i=0; i<3e4; i++){
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;

    int n, m;
    while(cin >> n){
        m = dp[n];
        // cout << m << endl;
        if(m>1){
            cout << "There are " << m << " ways to produce " << n << " cents change." << endl;
        }else{
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }
    }
}