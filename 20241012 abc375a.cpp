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
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;
    for(int i=0; i<n-2; i++){
        if(s[i]=='#' and s[i+1]=='.' and s[i+2]=='#'){
            ans += 1;
        }
    }
    
    cout << ans;
}
