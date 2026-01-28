// ==================================================
// Problem   : ABC061_C - Big Array
// URL       : https://atcoder.jp/contests/abc061/tasks/abc061_c
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
    
    int n, k;
    cin >> n >> k;

    map < int, int > mp;
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        mp[a] += b;
    }

    for(auto x: mp){
        k -= x.second;
        if(k <= 0){
            cout << x.first;
            break;
        }
    }

}
