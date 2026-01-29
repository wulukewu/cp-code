// ==================================================
// Problem   : ABC407_B - P(X or Y)
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc407/tasks/abc407_b
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
    int x, y;
    cin >> x >> y;

    set < pair < int, int > > s;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=6; j++){
            if(i+j>=x or abs(i-j)>=y){
                if(s.find(make_pair(i, j))==s.end()){
                    s.insert(make_pair(i, j));
                }
            }
        }
    }

    // for(auto i: s){
    //     cout << i.first << ' ' << i.second << endl;
    // }

    double ans = (double) s.size() / 36;
    // cout << ans;
    printf("%.12f", ans);
}
