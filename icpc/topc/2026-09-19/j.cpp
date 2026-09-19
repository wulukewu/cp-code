#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    vector<int>v;
    int c = 1;
    while(c<=2e18){
        v.push_back(c);
        c *= 2;
    }
    int n = v.size();
    int x;
    cin >> x;
    int ans = LLONG_MAX;
    for(int i: v){
        for(int j: v){
            ans = min(ans, abs(i+j-x));
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
    
}