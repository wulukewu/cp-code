// ==================================================
// Problem   : ABC387_B - 9x9 Sum
// URL       : https://atcoder.jp/contests/abc387/tasks/abc387_b
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
    
    int x;
    cin >> x;

    vector < vector < int > > arr(9, vector < int > (9));
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            arr[i][j] = (i+1)*(j+1);
        }
    }

    int sum = 0;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(arr[i][j] != x){
                sum+=arr[i][j];
            }
        }
    }

    cout << sum << endl;
}
