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
    
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0;
    int count = 0;

    for(int i=0; i<n; i++) {
        if(s[i] == 'X'){
            count = 0;
            continue;
        }
        count++;

        if(count >= k) {
            ans++;
            count = 0;
        }
    }

    cout << ans;
}
