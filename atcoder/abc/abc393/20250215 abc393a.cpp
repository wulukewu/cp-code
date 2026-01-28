// ==================================================
// Problem   : ABC393_A - Poisonous Oyster
// URL       : https://atcoder.jp/contests/abc393/tasks/abc393_a
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
    
    string s1, s2;
    cin >> s1 >> s2;

    if(s1=="sick"){
        if(s2=="sick"){
            cout << 1;
        }else{
            cout << 2;
        }
    }else{
        if(s2=="sick"){
            cout << 3;
        }else{
            cout << 4;
        }
    }
}
