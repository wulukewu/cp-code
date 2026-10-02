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
        bool has_ans = false;
        int ans = -LLONG_MAX;
        auto dfs = [&](auto&& self, int x, int y, int w) -> void {
            // cout << x << ' ' << y << ' ' << w << endl;
            if(x==n-1 and y==m-1){
                ans = max(ans, w);
                // cout << ans << endl;
                has_ans = true;
                return;
            }
            vis[x][y] = true;
            FOR(k, 0, 2){
                int r = x + offs[k][0];
                int c = y + offs[k][1];
                if(!(0<=r and r<n and 0<=c and c<m)) continue;
                if(vis[r][c]) continue;
                if(l[x][y]==3 and l[r][c]==3) continue;
                self(self, r, c, w+h[r][c]);
            }
            vis[x][y] = false;
        };
        dfs(dfs, 0, 0, h[0][0]);
        if(has_ans){
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