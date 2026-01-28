// ==================================================
// Problem   : ABC388_B - Heavy Snake
// URL       : https://atcoder.jp/contests/abc388/tasks/abc388_b
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
    
    int n, d;
    cin >> n >> d;

    vector < pair < int, int > > arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=1; i<=d; i++){
        int ans = -1;
        for(int j=0; j<n; j++){
            ans = max(ans, arr[j].first * (arr[j].second+i));
        }
        cout << ans << endl;
    }
    
}
