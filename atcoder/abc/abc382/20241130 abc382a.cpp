// ==================================================
// Problem   : ABC382_A - Daily Cookie
// URL       : https://atcoder.jp/contests/abc382/tasks/abc382_a
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

    string s;
    cin >> s;

    int m = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='@'){m++;}
    }

    cout << n-m+d;
}
