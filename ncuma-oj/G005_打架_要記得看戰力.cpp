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

    vector < int > brr(n);
    for(int i=0; i<n; i++){
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    reverse(brr.begin(), brr.end());

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    // for(int i=0; i<n; i++){
    //     cout << brr[i] << ' ';
    // }
    // cout << endl;

    int a = 0, b = 0;
    int ans = 0;
    while(a < n){
        if(brr[b] > arr[a]){
            ans++;
            a++;
            b++;
        }else{
            a++;
        }
    }
    cout << ans;
}