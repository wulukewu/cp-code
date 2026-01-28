// ==================================================
// Problem   : ABC376_C - Prepare Another Box
// URL       : https://atcoder.jp/contests/abc376/tasks/abc376_c
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

    vector <int> A(n);
    vector <int> B(n-1);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<n-1; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    // for(int i=0; i<n; i++){
    //     cout << A[i] << ' ';
    // }
    // cout << endl;

    // for(int i=0; i<n-1; i++){
    //     cout << B[i] << ' ';
    // }
    // cout << endl;

    int l = 0;
    int ans = -1;
    for(int i=0; i<n; i++){
        int j = i;
        int k = i-l;
        // cout << A[j] << ' ' << B[k] << endl;
        if(A[j] > B[k]){
            if(ans > -1){
                // cout << "break";
                ans = -1;
                break;
            }else{
                l = 1;
                ans = A[j];
                // cout << ans << endl;
            }
        }
    }

    cout << ans;
    
}
