// ==================================================
// Problem   : ABC389_A - 9x9
// URL       : https://atcoder.jp/contests/abc389/tasks/abc389_a
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
    
    string s;
    cin >> s;

    int a = s[0] - '0';
    int b = s[2] - '0';

    cout << a * b << endl;
}
