// ==================================================
// Problem   : ABC403_C - 403 Forbidden
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc403/tasks/abc403_c
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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m, q;
    cin >> n >> m >> q;

    vector < set < int > > arr(n);
    vector < int > brr(n, 0);
    int a, x, y;
    while(q--){
        cin >> a;
        if(a==1){
            cin >> x >> y;
            if(arr[x-1].find(y) == arr[x-1].end()){
                arr[x-1].insert(y);
            }
        }else if(a==2){
            cin >> x;
            brr[x-1] = 1;
        }else{
            cin >> x >> y;
            if(arr[x-1].find(y) != arr[x-1].end() or brr[x-1]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
