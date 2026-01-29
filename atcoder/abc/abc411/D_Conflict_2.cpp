// ==================================================
// Problem   : ABC411_D - Conflict 2
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc411/tasks/abc411_d
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
    int n, q;
    cin >> n >> q;

    vector < vector < int > > arr(n);
    vector < int > brr;
    vector < string > crr;
    int idx = -1;

    int a, p;
    string s;
    while(q--){
        cin >> a >> p;
        p--;

        if(a==1){
            arr[p] = brr;
        }else if(a==2){
            cin >> s;
            crr.push_back(s);
            idx++;
            arr[p].push_back(idx);
        }else{
            brr = arr[p];
        }
    }

    // for(auto i: crr){
    //     cout << i << ' ';
    // }
    // cout << endl;

    for(auto i: brr){
        cout << crr[i];
    }

    // vector < string > arr(n, "");

    // string ans = "";

    // int a, p;
    // string s;
    // while(q--){
    //     cin >> a >> p;
    //     p--;
    //     // cout << a << ' ' << p << endl;

    //     if(a==1){
    //         arr[p] = ans;
    //     }else if(a==2){
    //         cin >> s;
    //         arr[p] += s;
    //     }else{
    //         ans = arr[p];
    //     }

    //     // cout << ans << '_';
    //     // for(int i=0; i<n; i++){
    //     //     cout << arr[i] << '_';
    //     // }
    //     // cout << endl;
    // }

    // cout << ans;
}
