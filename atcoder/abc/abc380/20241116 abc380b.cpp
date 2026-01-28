// ==================================================
// Problem   : ABC380_B - Hurdle Parsing
// URL       : https://atcoder.jp/contests/abc380/tasks/abc380_b
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

    int t = 0;
    vector < int > ans;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='|'){
            ans.push_back(t);
            t = 0;
        }else{
            t++;
        }
    }

    for(int i=1; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}
