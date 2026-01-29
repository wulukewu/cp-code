// ==================================================
// Problem   : ABC413_A - Content Too Large
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc413/tasks/abc413_a
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
    int n, m;
    cin >> n >> m;

    int a;
    int b = 0;
    for(int i=0; i<n; i++){
        cin >> a;
        b += a;
    }

    if(b<=m){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
