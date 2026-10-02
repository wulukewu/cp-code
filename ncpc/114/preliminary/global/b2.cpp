#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=a; i<b; i++)


void solve(){
    while(true){
        int n, m;
        cin >> n >> m;
        if(n==0 and m==0) break;
        // cout << n << ' ' << m << endl;
        vector<vector<int>>h(n, vector<int>(m));
        FOR(i, 0, n){
            FOR(j, 0, m){
                cin >> h[i][j];
            }
        }
        vector<vector<int>>l(n, vector<int>(m));
        FOR(i, 0, n){
            FOR(j, 0, m){
                cin >> l[i][j];
            }
        }
        
        const int offs[2][2] = {{1, 0}, {0, 1}};
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vector<vector<int>>dp(n, vector<int>(m, LLONG_MIN));
        auto dfs = [&](auto&& self, int x, int y, int w) -> pair<int, bool> {
            // cout << x << ' ' << y << ' ' << w << endl;
            if(x==n-1 and y==m-1){
                return {0, true};
            }
            // vis[x][y] = true;
            int d = LLONG_MIN;
            bool dd = false;
            FOR(k, 0, 2){
                int r = x + offs[k][0];
                int c = y + offs[k][1];
                if(!(0<=r and r<n and 0<=c and c<m)) continue;
                if(vis[r][c]) continue;
                if(l[x][y]==3 and l[r][c]==3) continue;
                vis[r][c] = true;
                auto [z, det] = self(self, r, c, w+h[r][c]);
                // vis[r][c] = false;
                if(det){
                    d = max(d, z);
                    dd = true;
                }
            }
            // vis[x][y] = false;
            if(dd){
                dp[x][y] = max(dp[x][y], d + h[x][y]);
                return {dp[x][y], dd};
            }else{
                return {0, false};
            }
        };
        auto [ans, det] = dfs(dfs, 0, 0, h[0][0]);
        if(det){
            cout << ans << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
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