// ==================================================
// Problem   : ABC362_A - Buy a Pen
// URL       : https://atcoder.jp/contests/abc362/tasks/abc362_a
// ==================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
// #define int long long
using namespace std;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int r, g, b;
    cin >> r >> g >> b;

    string c;
    cin >> c;

    int a;
    if(c=="Red"){
        a = min(g, b);
    }
    else if(c=="Green"){
        a = min(r, b);
    }
    else{
        a = min(r, g);
    }

    cout << a;
}
