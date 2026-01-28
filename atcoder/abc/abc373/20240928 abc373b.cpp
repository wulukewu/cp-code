// ==================================================
// Problem   : ABC373_B - 1D Keyboard
// URL       : https://atcoder.jp/contests/abc373/tasks/abc373_b
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
    cin >> s;

    string S = "BCDEFGHIJKLMNOPQRSTUVWXYZ";

    int idx = s.find('A');
    int idx2;
    int ans = 0;
    // cout << idx;
    for(int i=0; i<25; i++){
        idx2 = s.find(S[i]);
        ans += abs(idx-idx2);
        idx = idx2;
    }
    cout << ans;
}
