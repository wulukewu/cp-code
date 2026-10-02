#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> times(1e9+7,0);
        vector<int> check;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            times[a]++;
            times[b]--;
            check.push_back(a);
            check.push_back(b);
        }
        sort(check.begin(),check.end());
        int past = -1 , ans = 0 , room = 0;
        for(int now : check){
            if(now == past) continue;
            past = now;
            room += times[now];
            ans = max(ans,room);
        }
        cout << ans << "\n";

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