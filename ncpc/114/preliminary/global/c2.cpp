#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second


void solve(){
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        vector<pair<int, int>>v(n);
        FOR(i, 0, n) cin >> v[i].F >> v[i].S;
        set<int>st;
        FOR(i, 0, n){
            st.insert(v[i].F);
            st.insert(v[i].S);
        }
        map<int, int>mp;
        int c = 1;
        int mx = 0;
        for(int x: st){
            mp[x] = c;
            // cout << c << ' ' << x << endl;
            mx = max(mx, c);
            c++;
        }

        int m = c+10;
        // cout << m << endl;
        vector<int>arr(m, 0);
        FOR(i, 0, n){
            // cout << mp[v[i].F] << ' ' << mp[v[i].S] << endl;
            arr[mp[v[i].F]]++;
            arr[mp[v[i].S]]--;
        }

        FOR(i, 1, m){
            arr[i] += arr[i-1];
        }

        // FOR(i, 0, m){
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;

        int ans = 1;
        FOR(i, 0, m){
            ans = max(ans, arr[i]);
        }
        cout << ans << endl;
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