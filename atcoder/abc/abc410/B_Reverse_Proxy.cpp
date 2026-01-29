// ==================================================
// Problem   : ABC410_B - Reverse Proxy
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc410/tasks/abc410_b
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

signed main() {
    int n, q;
    cin >> n >> q;

    vector < int > arr(n, 0);

    int x;
    for(int i=0; i<q; i++){
        int ans;
        cin >> x;
        if(x>=1){
            arr[x-1]++;
            ans = x-1;
        }else{
            int y = 0;
            for(int j=0; j<n; j++){
                if(arr[j] < arr[y]){
                    y = j;
                }
            }
            arr[y]++;
            ans = y;
        }

        // for(int j=0; j<n; j++){
        //     cout << arr[j] << ' ';
        // }
        // cout << endl;
        cout << ans + 1 << ' ';
    }
}
