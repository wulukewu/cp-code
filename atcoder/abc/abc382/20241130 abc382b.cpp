// ==================================================
// Problem   : ABC382_B - Daily Cookie 2
// URL       : https://atcoder.jp/contests/abc382/tasks/abc382_b
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
    
    int n, d;
    cin >> n >> d;

    string s;
    cin >> s;

    int m = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='@'){m++;}
    }

    int cookies = m-d;

    for(int i=0; i<n; i++){
        if(s[i]=='@' and cookies>0){
            cout << '@';
            cookies--;
        }else{
            cout << '.';
        }
    }
}
