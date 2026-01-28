// ==================================================
// Problem   : ABC388_C - Various Kagamimochi
// URL       : https://atcoder.jp/contests/abc388/tasks/abc388_c
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> A(n+1);
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int sum = 0;
    int k;
    for(int i=1; i<=n; i++){
        k=0;
        for(int j=i; j>=1; j/=2){
            while(A[k+j]*2 <= A[i]){
                k += j;
            }
        }
        sum += k;
        // cout << k << endl;
    }
    cout << sum;

}
