// ==================================================
// Problem   : ABC387_C - Snake Numbers
// URL       : https://atcoder.jp/contests/abc387/tasks/abc387_c
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
#include <fstream>

bool isSnakeNumber(long long num) {
    string s = to_string(num);
    char top_digit = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= top_digit) {
            return false;
        }
    }
    return true;
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long long L, R;
    cin >> L >> R;

    int count = 0;
    for (long long i = L; i <= R; i++) {
        if (isSnakeNumber(i)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}