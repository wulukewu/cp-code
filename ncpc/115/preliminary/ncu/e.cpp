#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    int n, k, m;
    cin >> n >> k >> m;
    
    vector<array<int, 3>>e(m);
    FOR(i, 0, m){
        cin >> e[i][0] >> e[i][1] >> e[i][2];
    }
    sort(e.begin(), e.end());

    int l = (1ll<<k);
    int ans = -1;
    FOR(t, 1, l+1){
        vector<array<int, 3>>take;
        int d = t;
        int c = 0;
        while(d){
            if(d%2==1){
                take.push_back(e[c]);
            }
            d /= 2;
            c++;
        }
        bool det = true;
        vector<bool>vis(k, false);
        for(auto eg: take){
            cout << eg[0] << ' ' << eg[1] << ' ' << eg[2] << endl;
            if(vis[eg[2]-1]){
                det = false;
                break;
            }else{
                vis[eg[2]-1] = true;
            }
        }
        cout << endl;
        int cur = 0;
        for(auto eg: take){
            if(eg[0]<=cur){
                cur = eg[1];
            }
        }
        if(cur==n){
            int sz = take.size();
            if(ans==-1) ans = sz;
            else ans = min(ans, sz);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
