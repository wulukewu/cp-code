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

int n;
vector <int> k;
int A, B;

int func(int idx){
    int a, b;
    A += k[idx];
    if(idx == n-1){
        a = max(A, B);
    }else{
        a = func(idx + 1);
    }
    A -= k[idx];

    B += k[idx];
    if(idx == n-1){
        b = max(A, B);
    }else{
        b = func(idx + 1);
    }
    B -= k[idx];

    // cout << A << ' ' << B << endl;
    return min(a, b);

    // if(idx == n-1){
    //     return min(a, b);
    // }else{
    //     func(idx + 1);
    // };
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin >> n;

    // vector <int> k(n); // KEY to use global vector k
    k.resize(n);
    for(int i=0; i<n; i++){
        cin >> k[i];
    }

    A = 0;
    B = 0;

    int ans = func(0);

    cout << ans;

    
}
