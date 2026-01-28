// ==================================================
// Problem   : ABC376_A - Candy Button
// URL       : https://atcoder.jp/contests/abc376/tasks/abc376_a
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
    
    int n, c;
    cin >> n >> c;

    vector < int > T(n);

    for(int i=0; i<n; i++) {
        cin >> T[i];
    }

    int last = T[0];
    int ans = 0;

    for(int i=1; i<n; i++){
        if(T[i] - last >= c){
            ans++;
            last = T[i];
        }
    }

    cout << ans + 1;
}
