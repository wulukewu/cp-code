#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<int> v(3000);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int n;
        cin >> n;
        v[n] += 1;
        v[n+3] -= 1;

        
        

        
    }

    int now = 0;
    for(int i = 0; i < v.size(); i++){
        now += v[i];
        if(now > 0){
            cnt += 1;
        }
    }

    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}