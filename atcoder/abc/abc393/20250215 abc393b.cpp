// ==================================================
// Problem   : ABC393_B - A..B..C
// URL       : https://atcoder.jp/contests/abc393/tasks/abc393_b
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
    
    string s;
    cin >> s;

    int n = s.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=1; i+2*j<n; j++){
            if(s[i]=='A' and s[i+j]=='B' and s[i+2*j]=='C'){
                cnt++;
            }
        }
    }

    cout << cnt;
}
