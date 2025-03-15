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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < int > k(n);
    vector < map < int, int > > a(n);
    int x;
    for(int i=0; i<n; i++){
        cin >> k[i];
        for(int j=0; j<k[i]; j++){
            cin >> x;
            a[i][x]++;
            // cout << x << ' ';
            // cout << a[i][x] << ' ';
        }
        // cout << endl;
    }

    long double y;
    vector < vector < long double > > arr(n, vector < long double > (100000, 0));
    for(int i=0; i<n; i++){
        for(auto j: a[i]){
            // cout << j.first << ' ' << j.second << ' ';
            y = (long double)j.second / (long double)k[i];
            arr[i][j.first-1] = y;
            // cout << j.second << ' ' << k[i] << ' ';
            cout << setprecision(15) << y << ' ';
        }
        cout << endl;
    }

    

}
