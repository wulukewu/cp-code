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

    vector < int > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    bool det = false;
    for(int i=2; i<n; i++){
        if(arr[i-2]==arr[i-1] and arr[i-1]==arr[i]){
            det = true;
            break;
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
