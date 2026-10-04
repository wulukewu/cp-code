#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    int m = 2*n;
    int sz = 0;
    // int num;
    vector<string>inp(m);
    FOR(i, 0, m){
        cin >> inp[i];
        sz += inp[i].length();
    }
    sz /= n;

    map<int, set<string>>mp;
    FOR(i, 0, m){
        mp[inp[i].size()].insert(inp[i]);
    }
}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}