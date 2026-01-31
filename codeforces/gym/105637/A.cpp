// ==================================================
// Problem   : 105637A - Unknown
// Submission Result: Runtime of 61 ms and Memory usage of 0 KB
// Runtime   : 61 ms
// Memory    : 0 KB
// URL       : https://codeforces.com/contest/105637/problem/A
// ==================================================

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0,in;
    while(n--){
        cin >> in;
        ans += in;
    }
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}