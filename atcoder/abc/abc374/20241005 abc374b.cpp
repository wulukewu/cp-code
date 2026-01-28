// ==================================================
// Problem   : ABC374_B - Unvarnished Report
// URL       : https://atcoder.jp/contests/abc374/tasks/abc374_b
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
    
    string s, t;
    cin >> s >> t;

    if(s==t){
        cout << 0;
    }else{
        int n = max(s.length(), t.length());
        if(s.length()<t.length()){
            s += '0'*(t.length()-s.length());
        }
        else if(t.length()<s.length()){
            t += '0'*(s.length()-t.length());
        }
        // cout << s << ' ' << t << endl;

        for(int i=0; i<n; i++){
            if(s[i]!=t[i]){
                cout << i+1;
                break;
            }
        }
    }

}
