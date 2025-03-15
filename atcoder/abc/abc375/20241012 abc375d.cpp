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
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int n;
    n = s.length();

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int k=i+2; k<n; k++){
            if(s[i] == s[k]){
                // cout << i << ' ' << k  << endl;
                ans += k-i-1;
            }
        }
    }

    cout << ans;

}
