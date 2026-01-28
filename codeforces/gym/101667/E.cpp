// ==================================================
// Problem   : 101667E.cpp - Unknown
// URL       : https://codeforces.com/contest/101667/problem/E.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ALL(v) v.begin(), v.end()
#define PB push_back 

solve(){
    int n, q, l, r;
    cin >> n >> q >> l >> r;
    vector<int> a;

    FOR(i, 0, n){
        int ai;
        cin >> ai;
        a.PB(ai);
    }

    sort(ALL(v));

    FOR(i, 0, q){
        int b;
        cin >> b;

        int rightwatch, rightshoot, leftwatch, leftshoot;
        rightwatch = 
    }


    
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}