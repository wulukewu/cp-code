// ==================================================
// Problem   : ABC373_A - September
// URL       : https://atcoder.jp/contests/abc373/tasks/abc373_a
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
    
    string s;
    int ans = 0;
    for(int i=0; i<12; i++){
        cin >> s;
        if(s.length()==i+1){
            ans += 1;
        }
    }
    cout << ans;
}
