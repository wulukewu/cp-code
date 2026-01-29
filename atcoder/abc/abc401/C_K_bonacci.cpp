// ==================================================
// Problem   : ABC401_C - K-bonacci
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc401/tasks/abc401_c
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
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int mod = 1e9;
    
    int n, k;
    cin >> n >> k;

    if(n<k){
        cout << 1;
        return 0;
    }else if(n==k){
        cout << k;
        return 0;
    }

    vector < int > arr(n+1, 0);
    for(int i=0; i<k; i++){
        arr[i] = 1;
    }
    arr[k] = k;
    for(int i=k+1; i<=n; i++){
        // arr[i] = 2 * arr[i-1] - arr[i-k-1];
        // arr[i] %= (int)1e9;

        // arr[i] = (2*arr[i-1]-arr[i-k-1]) % mod;
        // if(arr[i]<0){
        //     arr[i] += mod;
        // }

        arr[i] = 2*arr[i-1]-arr[i-k-1];
        if(arr[i]<0){
            arr[i] += mod;
        }
        arr[i] %= mod;
    }

    // for(int i=0; i<=n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    cout << arr[n];
}
