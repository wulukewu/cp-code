// ==================================================
// Problem   : ABC395_B - Make Target
// URL       : https://atcoder.jp/contests/abc395/tasks/abc395_b
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
    
    int n;
    cin >> n;

    int j;
    vector < vector < char > > arr(n, vector < char > (n, '.'));
    for(int i=0; i<n; i++){
        j = n-i;
        // cout << i << ' ' << j << endl;
        if(i<=j){
            for(int ii=i; ii<j; ii++){
                for(int jj=i; jj<j; jj++){
                    if(i%2==0){
                        arr[ii][jj] = '#';
                    }else{
                        arr[ii][jj] = '.';
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}
