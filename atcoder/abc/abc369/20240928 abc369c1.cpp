// ==================================================
// Problem   : ABC369_C - Count Arithmetic Subarrays
// URL       : https://atcoder.jp/contests/abc369/tasks/abc369_c
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

    vector < int > A (n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int ans;
    ans = n + n-1;

    for(int lr=2; lr<n; lr++){
        for(int l=0; l+lr<n; l++){
            int r = l+lr;
            int d = A[l+1]-A[l];
            bool det = true;
            for(int i=l+1; i<r; i++){
                if(A[i+1]-A[i]!=d){
                    det = false;
                    break;
                }
            }
            if(det){
                ans++;
                // cout << "(" << l << "," << r << "): " << ans << endl;
            }
        }
    }

    cout << ans;
}
