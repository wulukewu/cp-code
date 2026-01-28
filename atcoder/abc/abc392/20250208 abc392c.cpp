// ==================================================
// Problem   : ABC392_C - Bib
// URL       : https://atcoder.jp/contests/abc392/tasks/abc392_c
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < int > p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    vector < int > q(n);
    for(int i=0; i<n; i++){
        cin >> q[i];
    }

    map < int, int > mp;
    for(int i=0; i<n; i++){
        mp[q[i]] = p[i];
    }

    for(int i=0; i<n; i++){
        cout << q[mp[i+1]-1] << ' ';
    }

}
