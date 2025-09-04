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