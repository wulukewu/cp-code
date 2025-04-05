#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < int > arr;
    int l = 0;
    int r = 0;

    int k, t;
    for(int i=0; i<n; i++){
        cin >> k;
        if(k==1){
            cin >> t;
            arr.push_back(t);
            r++;
        }else if(k==2){
            if(l!=r){
                cout << arr[l] << endl;
            }else{
                cout << -1 << endl;
            }
        }else if(k==3){
            if(l!=r){
                l++;
            }
        }else{
            if(l!=r){
                cout << arr[r-1] << endl;
            }else{
                cout << -2 << endl;
            }
        }
    }
}