// ==================================================
// Problem   : ABC367_A - Shout Everyday
// URL       : https://atcoder.jp/contests/abc367/tasks/abc367_a
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
    
    int a, b, c;
    cin >> a >> b >> c;

    if(c < b){
        c += 24;
    }

    if(b==0){
        b = 24;
    }
    else if(a==0){
        a = 24;
    }

    if(a < b){
        a += 24;
    }

    if((b < a) && (a < c)){
        cout << "No";
    }else{
        cout << "Yes";
    }
}
