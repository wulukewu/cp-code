#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    vector < int > dp(n+1, 0);
    for(int i=1; i<=n; i++){
        if(arr[i-1]==0) dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    }

    int k;
    cin >> k;

    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        cout << dp[b] - dp[a-1] << ' ';
    }
}