// ==================================================
// Problem   : ABC386_B - Calculator
// URL       : https://atcoder.jp/contests/abc386/tasks/abc386_b
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

    int n = s.size();
    int m = 0;

    for(int i=0; i<n-1; i++){
        if(s[i]=='0' and s[i+1]=='0'){
            m++;
            i++;
        }
    }

    cout << n-m;

}
