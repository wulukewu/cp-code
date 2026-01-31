// ==================================================
// Problem   : 105383A - Unknown
// Submission Result: Runtime of 280 ms and Memory usage of 200 KB
// Runtime   : 280 ms
// Memory    : 200 KB
// URL       : https://codeforces.com/contest/105383/problem/A
// ==================================================

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;

    vector < string > a(n);
    vector < int > b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    int m = 0;
    for(int i=0; i<n; i++){
        if(a[i]=="pig"){
            m = max(m, b[i]);
        }
    }

    int ans = m;
    for(int i=0; i<n; i++){
        if(a[i]!="pig" and b[i]<m){
            ans += b[i];
        }
    }
    cout << ans << endl;
}