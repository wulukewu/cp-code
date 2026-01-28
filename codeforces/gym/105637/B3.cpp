// ==================================================
// Problem   : 105637B3.cpp - Unknown
// URL       : https://codeforces.com/contest/105637/problem/B3.cpp
// ==================================================

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double far;
    cin >> n >> far;
    int car;
    double time = -1;
    for(int i=1;i<=n;i++){
        double loc,speed,dis,t;
        cin >> loc >> speed;
        dis = far - loc;
        t = dis / speed;
        if(time == -1 or t < time){
            time = t;
            car = i;
        }
    }
    cout << car << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}