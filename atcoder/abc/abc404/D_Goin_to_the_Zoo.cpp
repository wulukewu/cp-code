// ==================================================
// Problem   : ABC404_D - Goin&#39; to the Zoo
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc404/tasks/abc404_d
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
    
    vector < int > c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    vector < int > k(m);
    vector < vector < int > > a(m);
    int aa;
    for(int i=0; i<m; i++){
        cin >> k[i];
        for(int j=0; j<k[i]; j++){
            cin >> aa;
            a[i].push_back(aa);
        }
    }
}
