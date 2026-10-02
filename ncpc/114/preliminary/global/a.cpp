#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    int n,m;
    while(true){
        cin >> n >> m;
        vector<int> nums(n);
        if(n == 0 and m == 0) break;
        for(int i=0;i<n;i++) cin >> nums[i];
        sort(nums.begin(),nums.end());


        int big = nums[n-1]-nums[0];
        for(int i=0;i<n-m;i++){
            big = min(big,nums[i+m-1]-nums[i]);
        }
        cout << big << "\n";
    } 
}


signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t= 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}