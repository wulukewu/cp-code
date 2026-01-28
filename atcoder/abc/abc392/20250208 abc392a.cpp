// ==================================================
// Problem   : ABC392_A - Shuffled Equation
// URL       : https://atcoder.jp/contests/abc392/tasks/abc392_a
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

    vector <int> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];

    sort(a.begin(), a.end());
    if(a[0]*a[1]==a[2]){
        cout << "Yes";
    } else {
        cout << "No";
    }
    
}
