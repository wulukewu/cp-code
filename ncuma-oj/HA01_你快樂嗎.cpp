#include <iostream>

using namespace std;

signed main(){
    int arr[4] = {0};
    for(int i=0; i<4; i++){
        cin >> arr[i];
    }
    
    if((arr[0]-arr[1])==(arr[1]-arr[2]) and (arr[1]-arr[2])==(arr[2]-arr[3])){
        cout << 2 * arr[3] - arr[2];
    }else if((arr[0]*arr[2]==arr[1]*arr[1]) and (arr[1]*arr[3]==arr[2]*arr[2])){
        cout << (int)arr[3]*arr[3]/arr[2];
    }else{
        cout << "關羽快樂嗎";
    }
}