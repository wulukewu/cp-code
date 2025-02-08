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
    
    string s;
    cin >> s;
    
    vector < char > arr(s.begin(), s.end());
    // for(int i=0; i<arr.size(); i++){
    //     cout << arr[i];
    // }

    int n=arr.size();
    for(int i=0; i<n-2; i++){
        if(arr[i]=='A' and arr[i+1]=='B' and arr[i+2]=='C'){
            arr.erase(arr.begin()+i, arr.begin()+i+3);
            n-=3;
            // i-=2;
            i = max(-1, i-3);
            // for(int i=0; i<n; i++){
            //     cout << arr[i];
            // }
            // cout << endl;
        }
    }
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
    
}
