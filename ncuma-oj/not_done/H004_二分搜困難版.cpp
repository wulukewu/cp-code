#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector < int > brr(n, 0);
    
    int m = arr[n-1];
    int m_idx = n-1;
    // for(int i=0; i<n; i++){
    //     if(arr[i] > m){
    //         m = arr[i];
    //         m_idx = i;
    //     }
    // }
    // cout << m << ' ' << m_idx << endl;

    int t = 0;
    while(true){
        // cout << "t=" << t << endl;
        // for(int i=0; i<n; i++){
        //     cout << arr[i]+brr[i]+t << ' ';
        // }cout << endl;
        
        if(m+t >= k) break;
        brr[m_idx]--;
        
        // for(int i=m_idx; i>0; i--){
        //     if(arr[i]+brr[i] < arr[i-1]+brr[i-1]){
        //         swap(arr[i], arr[i-1]);
        //         swap(brr[i], brr[i-1]);
        //     }else{
        //         // cout << "i=" << i << endl;
        //         break;
        //     }
        // }

        int l = 0;
        int r = n-1;
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            // cout << l << ' ' << r << ' ' << mid << endl;
            if(arr[mid]+brr[mid] < m){
                l = mid + 1;
            }else if(arr[mid]+brr[mid] > m){
                r = mid -1;
            }else{
                break;
            }
        }
        // cout << l << ' ' << r << endl;

        arr.insert(arr.begin()+l, arr[n-1]);
        arr.pop_back();
        brr.insert(brr.begin()+l, brr[n-1]);
        brr.pop_back();

        m_idx = n-1;
        m = arr[n-1]+brr[n-1];

        t++;
    }

    cout << t-1;
}