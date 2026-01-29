// ==================================================
// Problem   : ABC400_B - Sum of Geometric Series
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc400/tasks/abc400_b
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
    
    int n, m;
    cin >> n >> m;

    int j = 1;
    int ans = 0;
    for(int i=0; i<=m; i++){
        ans += j;
        j *= n;
        if(ans > 1e9)break;
    }

    if(ans > 1e9){
        cout << "inf";
    }else{
        cout << ans;
    }
    
}
