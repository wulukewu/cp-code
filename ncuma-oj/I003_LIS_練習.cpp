#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < int > x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    vector < int > arr;
    int m = 0;

    for(int i=0; i<n; i++){
        if(m==0){
            arr.push_back(x[i]);
            m++;
        }else if(x[i] > arr[m-1]){
            arr.push_back(x[i]);
            m++;
        }else{
            int l = 0;
            int r = m-1;
            while(l<=r){
                int mid = l + (r - l) / 2;
                if(arr[mid] < x[i]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            arr[l] = x[i];
        }
    }
    
    cout << arr.size();
}