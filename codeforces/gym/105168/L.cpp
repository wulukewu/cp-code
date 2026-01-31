// ==================================================
// Problem   : 105168L - Unknown
// Submission Result: Runtime of 764 ms and Memory usage of 100 KB
// Runtime   : 764 ms
// Memory    : 100 KB
// URL       : https://codeforces.com/contest/105168/problem/L
// ==================================================

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ALL(v) v.begin(), v.end()
#define PB push_back
#define endl '\n'
// #define int long long
#define FOR(i, a ,b) for(int i = a; i< b; i++)

void solve(){
    int n;
    cin >> n;

    int ans_p = 0;
    int ans_t = 0;

    int p, t;
    FOR(i, 0, n){
        cin >> p >> t;
        ans_p = max(ans_p, p);
        ans_t = max(ans_t, p+t);
    }

    cout << ans_p << ' ' << ans_t << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}