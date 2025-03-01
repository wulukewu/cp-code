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
    
    int n;
    cin >> n;

    int x;
    cin >> x;
    int y;
    bool det = true;
    for(int i=1; i<n; i++){
        cin >> y;
        if(x>=y){
            det = false;
        }
        x = y;
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
