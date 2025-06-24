#include <iostream>
#include <vector>

using namespace std;

int main(){
    int r;
    cin >> r;

    vector < vector < int > > arr(r, vector < int > (r, 0));
    for(int i=0; i<r; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }

    // for(int i=0; i<r; i++){
    //     for(int j=0; j<r; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for(int i=r-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }
    
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<r; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << arr[0][0];
}