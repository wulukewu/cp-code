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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
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

    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            int a = x;
            int b = y;
            int c = min(x, n-x-1);
            int d = min(y, n-y-1);
            int k = min(c, d);
            for(int i=0; i<(k+1); i++){
                int t = a;
                a = b;
                b = n-t-1;
            }
            brr[a][b] = arr[x][y];
        }
    }
    arr = brr;

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
