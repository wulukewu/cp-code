// ==================================================
// Problem   : ABC390_B - Geometric Sequence
// URL       : https://atcoder.jp/contests/abc390/tasks/abc390_b
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

    vector < int > A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    bool det = true;
    for(int i=0; i<n-2; i++){
        if(A[i]*A[i+2]!=A[i+1]*A[i+1]){
            det = false;
            break;
        }
    }

    if(det){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
