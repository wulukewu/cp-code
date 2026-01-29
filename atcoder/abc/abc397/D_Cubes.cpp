// ==================================================
// Problem   : ABC397_D - Cubes
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc397/tasks/abc397_d
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
    
    int n;
    cin >> n;

    int m = 1e7;

    vector < int > arr(m);
    for(int i=0; i<m; i++){
        // arr[i] = pow((i+1), 3);
        arr[i] = (i+1)*(i+1)*(i+1);
    }

    int x=0;
    int goal;
    bool minus_one = false;
    for(int y=0; y<m; y++){
        goal = n + arr[y];
        while(arr[x]<goal){
            x++;
            if(x>=m){
                // cout << -1;
                minus_one = true;
                break;
            }
        }
        if(arr[x]==goal){
            cout << x+1 << ' ' << y+1;
            break;
        }
    }

    if(minus_one){
        cout << -1;
    }
}
