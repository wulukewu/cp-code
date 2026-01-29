// ==================================================
// Problem   : ABC411_A - Required Length
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc411/tasks/abc411_a
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
    string p;
    cin >> p;

    int l;
    cin >> l;

    if(p.size()>=l){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
