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
    
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    vector <int> v(4);
    v[0] = a1;
    v[1] = a2;
    v[2] = a3;
    v[3] = a4;
    
    vector <int> arr(4,0);

    for(int i=0; i<4; i++) {
        arr[v[i]-1]++;
    }
    
    int ans = 0;
    for(int i=0; i<4; i++) {
        if(arr[i] > 1){
            ans += arr[i]/2;
        };
    }

    cout << ans;

}
