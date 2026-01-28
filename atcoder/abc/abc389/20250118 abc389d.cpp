// ==================================================
// Problem   : ABC389_D - Squares in Circle
// URL       : https://atcoder.jp/contests/abc389/tasks/abc389_d
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int r;
    cin >> r;

    float x, y;
    x = r-0.5;
    y = 0.5;

    int sum = 0;

    while(x>0){
        // cout << x << ' ' << y << ' ';
        if(pow(x,2)+pow(y,2) <= pow(r,2)){
            sum += (x-0.5);
            // x--;
            y++;
        }else{
            x--;
        }
        // cout << sum << endl;
    }
    cout << 1 + sum*4;
}
