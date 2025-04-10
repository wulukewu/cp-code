#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        cout << arr[i];
        if(i!=n-1) cout << ' ';
    }
}