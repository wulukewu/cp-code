// ==================================================
// Problem   : ABC389_C - Snake Queue
// URL       : https://atcoder.jp/contests/abc389/tasks/abc389_c
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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int q;
    cin >> q;

    vector < int > arr;
    arr.push_back(0);
    int i=0;
    int n;

    int form, l, k;
    for(int qq=0; qq<q; qq++){
        cin >> form;
        if(form == 1){
            cin >> l;
            n = arr.size();
            arr.push_back(arr[n-1]+l);
        }else if(form == 2){
            n = arr.size();
            // for(int j=i+1; j<n; j++){
            //     arr[j] -= arr[i];
            // }
            i++;
        }else {
            cin >> k;
            cout << arr[i+k-1] - arr[i] << endl;
        }
        // if(i==0){
        //     i++;
        // }
    }
    // n = arr.size();
    // for(int j=0; j<n; j++){
    //     cout << arr[j] << " ";
    // }
}
