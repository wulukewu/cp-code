#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector < int > dp(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> dp[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] += dp[i-1];
    }

    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << endl;
    }
}