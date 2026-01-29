// ==================================================
// Problem   : 105637E2 - Unknown
// URL       : https://codeforces.com/contest/105637/problem/E2
// ==================================================

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector < string > arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector < vector < bool > > v(n, vector < bool > (m, false));

    int cnt = 0;
    // left
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='o') break;
            if(!v[i][j]){
                cnt++;
                v[i][j] = true;
            }
        }
    }
    // right
    for(int i=0; i<n; i++){
        for(int j=m-1; j>=0; j--){
            if(arr[i][j]=='o') break;
            if(!v[i][j]){
                cnt++;
                v[i][j] = true;
            }
        }
    }
    // up
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            if(arr[i][j]=='o') break;
            if(!v[i][j]){
                cnt++;
                v[i][j] = true;
            }
        }
    }
    // down
    for(int j=0; j<m; j++){
        for(int i=n-1; i>=0; i--){
            if(arr[i][j]=='o') break;
            if(!v[i][j]){
                cnt++;
                v[i][j] = true;
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}