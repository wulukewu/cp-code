#include <iostream>
#include <vector>

using namespace std;

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    vector < vector < int > > arr(n, vector < int > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    vector < vector < int > > brr(n, vector < int > (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            brr[n-j-1][i] = arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << brr[i][j];
            if(j!=n-1){
                cout << ' ';
            }
        }
        cout << endl;
    }
    
        
}