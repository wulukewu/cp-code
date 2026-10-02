#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve(){
    while(true){
        
        int m, n, q;
        cin >> m >> n >> q;
        if(n == 0 and m == 0 and q == 0){
            break;
        }

        vector<int>trip(m);
        vector<int>p(n);
        for(int i = 0; i < m; i++){
            cin >> trip[i];
        }

        // for(int i = 0; i < m; i++){
        //     cout << trip[i] << " ";
        // }
        // cout << endl;

        int r = -1;
        for(int i = 0; i < n; i++){
            cin >> p[i];
            r = max(r, p[i]);
        }

        // for(int i = 0; i < n; i++){
        //     cout << p[i] << " ";
        // }
        // cout << endl;

        //cout << r << endl;

        int l = 1;
        int ans = -1; 
        while(l <= r){
            int middle = l + (r-l)/2;
            vector<bool>ok(n);
            // cout << 123 << endl;

            for(int i = 0; i < n; i++){
                if(p[i] > middle){
                    ok[i] = true;
                }else{
                    ok[i] = false;
                }
            }


            int cnt = 0;
            int idx = 0;
            for(int i = 0; i < n; i++){
                if(ok[i] == true){
                    cnt += 1;
                }else{
                    cnt = 0;
                }

                //cout << cnt << ' ' << trip[idx] << endl;
                if(cnt == trip[idx]){
                    i += q;
                    idx ++;
                    cnt = 0;
                }

                if(idx==m) break;
            }

            //cout << idx << endl;
            if(idx == m){
                //cout << middle << endl;
                l = middle + 1;
                ans = max(ans, middle);
            }else{
                 r = middle - 1;
            }
            
        }     
        cout << ans+1 << endl;
    }
    
}


signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t= 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}