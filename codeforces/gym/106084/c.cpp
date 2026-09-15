#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
#define int long long

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> room(n+1,0);
    for(int i=0;i<m;i++){
        int x,y,v;
        cin >> x >> y >> v;
        // cout << x << " " << y << " " << v << endl;
        int nowx = room[x] , nowy = room[y];
        room[x] = nowy + v;
        room[y] = nowx + v;
    }
    int ans = 0;
    for(int a : room) ans = max(ans,a);
    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}