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
        sort(v.rbegin(), v.rend());
    
        int l = max(v[0], (sum+m-1)/m);
        int r = sum;
        int ans = sum;
        while(l<=r){
            int mid = l + (r-l)/2;
            vector<int>arr(m, mid);

            auto dfs = [&](auto&& self, int idx) -> bool {
                if(idx==n){
                    return true;
                }
                FOR(i, 0, m){
                    if(arr[i]<v[idx]) continue;

                    bool same = false;
                    FOR(j, 0, i){
                        if(arr[j]==arr[i]){
                            same = true;
                            break;
                        }
                    }
                    if(same) continue;

                    int before = arr[i];
                    arr[i] -= v[idx];
                    if(self(self, idx+1)) return true;
                    arr[i] = before;
                    if(before==mid) return false;
                    if(before==v[idx]) return false;
                }
                return false;
            };
            bool det = dfs(dfs, 0);

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