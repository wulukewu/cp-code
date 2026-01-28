// ==================================================
// Problem   : ABC375_C - Spiral Rotation
// URL       : https://atcoder.jp/contests/abc375/tasks/abc375_c
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
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < vector < int > > arr(n, vector < int > (n, 0));
    vector < vector < int > > brr(n, vector < int > (n, 0));
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        for(int j=0; j<n; j++){
            if(s[j]=='#'){
                arr[i][j] = 1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    brr = arr;

    for(int i=1; i<(n/2+1); i++){
        for(int x=i-1; x<(n+1-i); x++){
            for(int y=i-1; y<(n+1-i); y++){
                // cout << i << ' ' << x << ' ' << y << endl;
                // cout << i << x  << y << "\t";
                // arr[y-1][n+1-x-1] = arr[x-1][y-1];
                // cout << y-1 << ' ' << n+1-x-1 << ' ' << x-1 << ' ' << y-1 << endl;
                // cout << y-1 << n+1-x-1 << x-1 << y-1 << "\t";
                brr[y][n-x-1] = arr[x][y];
            }
            // cout << endl;
        }
        arr = brr;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(arr[i][j]){
        //             cout << '#';
        //         }else{
        //             cout << '.';
        //         }
        //     }
        //     cout << endl;
        // }
        // for(int i=0; i<n; i++){
        //     cout << '-';
        // }
        // cout << endl;
        
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }

}
