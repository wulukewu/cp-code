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

    int q;
    cin >> q;
    
    int x;
    while(q--){
        cin >> x;

        int l = 0;
        int r = n-1;
        int mid;

        int ans = -1;
        while(l<=r){
            mid = l + (r-l)/2;
            // cout << l << ' ' << r << ' ' << mid << endl;
            if(arr[mid] > x){
                r = mid-1;
            }else if(arr[mid] < x){
                l = mid+1;
            }else{
                ans = mid;
                break;
            }
        }

        if(ans>-1){
            cout << ans << endl;
        }else{
            cout << "not find" << endl;
        }
    }
}