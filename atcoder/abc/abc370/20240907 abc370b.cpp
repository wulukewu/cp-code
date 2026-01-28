// ==================================================
// Problem   : ABC370_B - Binary Alchemy
// URL       : https://atcoder.jp/contests/abc370/tasks/abc370_b
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

    vector < vector <int> > A(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int k;
            cin >> k;
            A[i].push_back(k);
            // cout << k << ' ';
        }
        // cout << endl;
    }

    int i = 0;
    int ans;
    for(int j=0; j<n; j++){
        if(i>=j){
            ans = A[i][j];
        }else{
            ans = A[j][i];
        }

        i = ans - 1;
        // cout << ans << endl;
    }
    cout << ans;
}
