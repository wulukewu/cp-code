// ==================================================
// Problem   : ABC397_B - Ticket Gate Log
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc397/tasks/abc397_b
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
#include <stack>
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

    int n=s.size();
    int ans = 0;
    char last = 'o';
    for(int i=0; i<n; i++){
        if(s[i]==last){
            ans++;
        }
        last = s[i];
    }
    if(last=='i'){
        ans++;
    }

    cout << ans;
}
