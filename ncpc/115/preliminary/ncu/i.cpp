#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    vector<array<int, 3>>v(3);
    int g = 0, r = 0, y = 0;
    FOR(i, 0, 3){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        g += v[i][0];
        r += v[i][1];
        y += v[i][2];
    }
    
    int ans = 1e10;
    FOR(i, 0, 3){
        FOR(j, 0, 3){
            FOR(k, 0, 3){
                if(i==j or j==k or i==k) continue;
                int res = g-v[i][0]+r-v[j][1]+y-v[k][2];
                ans = min(ans, res);
            }
        }
    }
    cout << ans << endl;

    // vector<array<int, 3>>v;
    // int g, r, y;
    // int sg = 0;
    // int sr = 0;
    // int sy = 0;
    // int mg = 0;
    // int mr = 0;
    // int my = 0;
    // while(cin >> g >> r >> y){
    //     v.push_back({g, r, y});
    //     sg += g;
    //     sr += r;
    //     sy += y;
    //     mg = max(mg, g);
    //     mr = max(mr, r);
    //     my = max(my, y);
    // }
    // int ans = sg+sr+sy-mg-mr-my;
    // cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}