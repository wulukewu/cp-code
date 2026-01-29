// ==================================================
// Problem   : ABC408_A - Timeout
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc408/tasks/abc408_a
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
    int n, s;
    cin >> n >> s;

    vector < int > t(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    bool det = true;
    if(t[0]>s){
        det = false;
    }else{
        for(int i=0; i<n-1; i++){
            if(t[i+1]-t[i]>s){
                det = false;
                break;
            }
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
