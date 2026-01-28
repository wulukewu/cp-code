// ==================================================
// Problem   : ABC378_C - Repeating
// URL       : https://atcoder.jp/contests/abc378/tasks/abc378_c
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

    vector < int > A(n);
    for(int i=0; i<n; i++) {
        cin >> A[i];
    }

    vector < vector < int > > arr(pow(10,9));
    for(int i=0; i<n; i++) {
        arr[A[i]-1].push_back(i+1);
    }
    // cout << '-' << endl;

    // for(int i=0; i<pow(10,9); i++) {
    //     int m=arr[i].size();
    //     for(int j=0; j<m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<n; i++) {
        int m = arr[A[i]-1].size();
        if(m == 0) {
            cout << -1 << ' ';
        } else {
            int ans = -1;
            for(int j=0; j<m; j++){
                if(arr[A[i]-1][j] < i+1){
                    ans = arr[A[i]-1][j];
                }
            }
            cout << ans << ' ';
        }
    }
}
