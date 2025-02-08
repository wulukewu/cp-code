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
    
    vector < int > arr(5);
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    vector < int > ans(5);
    ans[0] = 1;
    ans[1] = 2;
    ans[2] = 3;
    ans[3] = 4;
    ans[4] = 5;

    vector < int > diff;
    for(int i = 0; i < 5; i++) {
        // cout << arr[i] << " " << ans[i] << endl;
        if(arr[i] != ans[i]) {
            diff.push_back(i);
        }
    }

    bool det = false;
    if(diff.size() == 2) {
        // cout << diff[0] << " " << diff[1] << endl;
        if(abs(diff[0]-diff[1])==1){
            det = true;
        }
    }

    if(det){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
