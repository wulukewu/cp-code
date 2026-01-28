// ==================================================
// Problem   : ABC393_C - Make it Simple
// URL       : https://atcoder.jp/contests/abc393/tasks/abc393_c
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
    
    int n, m;
    cin >> n >> m;

    set < pair<int, int> > arr;

    int cnt = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(a==b){
            cnt++;
        }else if(arr.count(make_pair(a, b)) or arr.count(make_pair(b, a))){
            cnt++;
        }else{
            arr.insert(make_pair(a, b));
            arr.insert(make_pair(b, a));
        }
    }
    cout << cnt;
}
