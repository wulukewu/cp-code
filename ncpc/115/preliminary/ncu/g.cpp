#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define F first
#define S second

struct DSU {
    vector<int> siz;
    vector<int> f;
    vector<array<int, 2>> his;

    DSU(int n) : siz(n+1, 1), f(n+1){
        iota(f.begin(), f.end(), 0);
    }

    int find
}



void solve(){
    int n, m;
    cin >> n >> m;

}

signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}