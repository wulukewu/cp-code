#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int q;
    cin >> q;

    int n_max = 1000;
    int k_max = 1000;
    
    vector < vector < int > > arr(n_max+1, vector < int > (k_max+1, 0));
    for(int i=0; i<=n_max; i++){
        for(int j=0; j<=min(i, k_max); j++){
            if(j==0 or j==i){
                arr[i][j] = 1;
            }else{
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10000;
            }
        }
    }

    // cout << '-' << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int n, k;
    while(q--){
        cin >> n >> k;
        cout << arr[n][k] << endl;
    }
}