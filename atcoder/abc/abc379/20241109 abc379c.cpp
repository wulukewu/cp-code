// ==================================================
// Problem   : ABC379_C - Sowing Stones
// URL       : https://atcoder.jp/contests/abc379/tasks/abc379_c
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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector < int > X(m);
    vector < int > A(m);

    for(int i=0; i<m; i++) {
        cin >> X[i];
    }

    int s = 0;
    for(int i=0; i<m; i++) {
        cin >> A[i];
        s += A[i];
    }
    
    if(s != n) {
        cout << -1;
        exit(0);
    }

    vector < pair < int, int > > arr(m+1);
    for(int i=0; i<m; i++) {
        arr[i] = make_pair(X[i], A[i]);
    }
    arr[m] = make_pair(n, 0);
    sort(arr.begin(), arr.end());

    // for(int i=0; i<m+1; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << endl;
    // }

    if(arr[0].first != 1) {
        cout << -1;
        exit(0);
    }

    int k = 0;
    int ans = 0;
    int a, b, c;
    for(int i=0; i<m; i++) {
        a = arr[i+1].first - arr[i].first;
        b = arr[i].second;
        if(a > b + k) {
            cout << -1;
            exit(0);
        }

        c = b + k - a;
        ans += (a-1)*a/2;

        ans += a * c;
        k = c;
    }

    cout << ans;
    
}
