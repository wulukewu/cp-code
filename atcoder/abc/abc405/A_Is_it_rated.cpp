// ==================================================
// Problem   : ABC405_A - Is it rated?
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc405/tasks/abc405_a
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
    int r, x;
    cin >> r >> x;

    if((1600<=r and r<=2999 and x==1) or (1200<=r and r<=2399 and x==2)){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
