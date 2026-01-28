// ==================================================
// Problem   : ABC387_C - Snake Numbers
// URL       : https://atcoder.jp/contests/abc387/tasks/abc387_c
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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
#include <fstream>


signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int l, r;
    cin >> l >> r;

    string L = to_string(l);
    string R = to_string(r);

    int ans = 0;
    int n = L.size();
    int nn = R.size();

    // from left
    int left = L[0] - '0';
    // cout << left << endl;

    for(int i=left; i<=9; i++){
        int m = 1;
        for(int j=1; j<n; j++){
            m *= max(1, i - (L[j] - '0'));
        }
        // cout << m << endl;
        ans += m;
    }
    cout << ans << endl;

    // to pow(10, nn+1)-1
    int now;
    for(int i=n; i<nn; i++){
        now = pow(10, i);
        cout << now << endl;

        for(int j=1; j<=9; j++){
            ans += pow(j, i);
        }
    }
    cout << ans << endl;

    // minus to r
    // r++;
    // R = to_string(r);
    // // nn = R.size();

    left = R[0] - '0';
    // cout << left << endl;

    for(int i=left; i<=9; i++){
        int m = 1;
        for(int j=1; j<nn; j++){
            m *= max(1, i - (R[j] - '0'));
        }
        cout << m << endl;
        ans -= m;
    }
    cout << ans << endl;

}
