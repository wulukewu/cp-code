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
    
    int l, r;
    cin >> l >> r;

    if(l == 1){
        if(r == 1){
            cout << "Invalid";
        }else{
            cout << "Yes";
        }
    }else{
        if(r == 1){
            cout << "No";
        }else{
            cout << "Invalid";
        }
    }

}
