#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<b; i++)
int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    FOR(i, 0, n) cin >> v[i];

    int cur = 0;
    int res = 0;
    FOR(i, 0, n){
        cur = max(v[i], cur+v[i]);
        res = max(res, cur);
    }
    cout << res << endl;
}