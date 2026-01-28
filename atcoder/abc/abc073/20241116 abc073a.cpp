// ==================================================
// Problem   : ABC073_A - September 9
// URL       : https://atcoder.jp/contests/abc073/tasks/abc073_a
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
    
    string n;
    cin >> n;

    char a = n[0];
    char b = n[1];

    if(a=='9' || b=='9'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
