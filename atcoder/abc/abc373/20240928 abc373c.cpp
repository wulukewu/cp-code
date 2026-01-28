// ==================================================
// Problem   : ABC373_C - Max Ai&#43;Bj
// URL       : https://atcoder.jp/contests/abc373/tasks/abc373_c
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

    vector < int > A(n);
    for(int i=0; i<n; i++){
        cin  >> A[i];
    }
    vector < int > B(n);
    for(int i=0; i<n; i++){
        cin  >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // for(int i=0; i<n; i++){
    //     cout << A[i] << ' ';
    // }
    // cout << endl;

    // for(int i=0; i<n; i++){
    //     cout << B[i] << ' ';
    // }
    // cout << endl;

    cout << A[n-1]+B[n-1];
}
