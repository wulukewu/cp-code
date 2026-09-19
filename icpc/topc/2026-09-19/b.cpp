#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'

void solve(){
    int c,h,o;
    cin >> c >> h >> o;
    if(c*2-4 == h) cout << "Saturated\n";
    else cout << "Unsaturated\n";
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