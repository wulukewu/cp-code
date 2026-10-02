#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(), v.end()


void solve(){
    while(true){
        int n, m;
        cin >> n >> m;
        if(n==0 and m==0) break;
        vector<int>v(n);
        int sum = 0;
        FOR(i, 0, n){
            cin >> v[i];
            sum += v[i];
        }
        sort(ALL(v));
        reverse(ALL(v));
    
        int l = 1;
        int r = sum;
        int ans = n;
        while(l<=r){
            int mid = l + (r-l)/2;
            bool det = true;
            vector<int>arr(m, mid);
            FOR(i, 0, n){
                bool det2 = false;
                FOR(j, 0, m){
                    if(arr[j]>=v[i]){
                        arr[j] -= v[i];
                        det2 = true;
                        break;
                    }
                }
                if(!det2){
                    det = false;
                }
            }
            if(det){
                r = mid - 1;
                ans = min(ans, mid);
            }else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
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