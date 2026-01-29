// ==================================================
// Problem   : ABC398_B - Full House 3
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc398/tasks/abc398_b
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
 
    vector < int > arr(13, 0);

    int a;
    for(int i=0; i<7; i++){
        cin >> a;
        arr[a-1]++;
    }

    // for(int i=0; i<13; i++){
    //     cout << arr[i] << ' ';
    // }cout << endl;

    bool det = false;
    for(int i=0; i<13; i++){
        for(int j=i+1; j<13; j++){
            if((arr[i]>=2 and arr[j]>=3) or (arr[i]>=3 and arr[j]>=2)){
                det = true;
                break;
            }
        }
        if(det){
            break;
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }

    
}
