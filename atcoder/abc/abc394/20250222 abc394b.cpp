// ==================================================
// Problem   : ABC394_B - cat
// URL       : https://atcoder.jp/contests/abc394/tasks/abc394_b
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
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < pair < int, string > > s;
    string t;
    for(int i=0; i<n; i++){
        cin >> t;
        s.push_back(make_pair(t.size(), t));
    }

    sort(s.begin(), s.end());

    for(int i=0; i<n; i++){
        cout << s[i].second;
    }

}
