// ==================================================
// Problem   : ABC368_B - Decrease 2 max elements
// URL       : https://atcoder.jp/contests/abc368/tasks/abc368_b
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector <int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int t=0;
    while(true){
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        A[0]--;
        A[1]--;

        // for(int i=0; i<n; i++){
        //     cout << A[i] << ' ';
        // }
        // cout << endl;

        t++;

        int s=0;
        for(int i=0; i<n; i++){
            if(A[i]>0){s++;}
        }
        if(s<=1){
            break;
        }

    }
    cout << t;

}
