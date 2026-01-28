// ==================================================
// Problem   : ABC073_B - Theater
// URL       : https://atcoder.jp/contests/abc073/tasks/abc073_b
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

    int l, r;
    vector <int> arr(100000, 0);
    for(int i=0; i<n; i++){
        cin >> l >> r;
        arr[l-1] += 1;
        arr[r] -= 1;
    }

    // for(int i=1; i<100000; i++){
    //     cout << arr[i] << " ";
    // }

    int ans = 0;
    int state = 0;
    for(int i=0; i<100000; i++){
        if(arr[i]==1){
            state += 1;
        }else if(arr[i]==-1){
            state -= 1;
        }
        
        if(state>=1){
            ans++;
        }
    }
    cout << ans;
}
