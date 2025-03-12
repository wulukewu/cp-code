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
    
    string d;
    cin >> d;

    int n=d.size();
    for(int i=0; i<n; i++){
    if(d[i]=='N'){
        cout << "S";
    }else if(d[i]=='E'){
        cout << "W";
    }else if(d[i]=='W'){
        cout << "E";
    }else if(d[i]=='S'){
        cout << "N";
    }
    }
}
