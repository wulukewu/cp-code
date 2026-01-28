// ==================================================
// Problem   : 105637B.cpp - Unknown
// URL       : https://codeforces.com/contest/105637/problem/B.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, f;
    cin >> n >> f;

    int ansidx = 1;
    double anssecond = -1;
    for(int i = 1; i <= n; i++){
        double time;
        int where, speed;

        cin >> where >> speed;
        time = (f - where) / speed;

        if(anssecond == -1 or time < anssecond){
            ansidx = i;
            anssecond = time;
        }
    }

    cout << ansidx << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}