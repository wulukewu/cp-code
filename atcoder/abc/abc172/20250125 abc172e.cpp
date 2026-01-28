// ==================================================
// Problem   : ABC172_E - NEQ
// URL       : https://atcoder.jp/contests/abc172/tasks/abc172_e
// ==================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector < int > fact(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int ans = 0;
    int a;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            a = fact[n]*fact[m-n]/fact[j]/fact[n-2*i]/fact[m-2*n+j];
        }
    }
    ans = ans % 1000000007;
    cout << ans << endl;


}
