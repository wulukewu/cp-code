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
    
    string s, t;
    cin >> s >> t;

    int x = 0;
    int n = s.size();
    vector < int > arr(n, 0);

    for(int i=0; i<n; i++){
        arr[i] = t[i] - s[i];
        if(arr[i]!=0){
            x++;
        }
        // cout << arr[i] << ' ';
    }
    // cout << endl;
    cout << x << endl;

    for(int i=0; i<n; i++){
        if(arr[i]<0){
            s[i] = t[i];
            cout << s << endl;
            arr[i] = 0;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(arr[i]>0){
            s[i] = t[i];
            cout << s << endl;
            arr[i] = 0;
        }
    }
}
