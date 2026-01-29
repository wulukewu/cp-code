// ==================================================
// Problem   : ABC409_A - Conflict
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc409/tasks/abc409_a
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
    int n;
    cin >> n;

    string t, a;
    cin >> t >> a;

    bool ans = false;
    for(int i=0; i<n; i++){
        if(t[i]=='o' and a[i]=='o'){
            ans = true;
            break;
        }
    }

    if(ans){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
