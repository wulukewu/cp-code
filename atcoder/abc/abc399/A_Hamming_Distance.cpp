// ==================================================
// Problem   : ABC399_A - Hamming Distance
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc399/tasks/abc399_a
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

    int n;
    string s, t;
    cin >> n >> s >> t;

    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i]!=t[i]){
            ans++;
        }
    }
    
    cout << ans;
}
