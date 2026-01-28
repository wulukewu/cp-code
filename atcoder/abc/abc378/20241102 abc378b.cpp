// ==================================================
// Problem   : ABC378_B - Garbage Collection
// URL       : https://atcoder.jp/contests/abc378/tasks/abc378_b
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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector < int > Q(n);
    vector < int > R(n);
    for(int i=0; i<n; i++) {
        cin >> Q[i] >> R[i];
    }

    int q;
    cin >> q;
    vector < int > t(q);
    vector < int > d(q);
    for(int i=0; i<q; i++) {
        cin >> t[i] >> d[i];
    }

    // vector < int > arr(q,0);
    for(int i=0; i<q; i++) {
        int qq = Q[t[i]-1];
        int rr = R[t[i]-1];

        int offs = (rr - d[i] % qq + qq) % qq;
        // cout << offs << endl;
        cout << d[i] + offs << endl;
    }
}
