// ==================================================
// Problem   : ABC392_B - Who is Missing?
// URL       : https://atcoder.jp/contests/abc392/tasks/abc392_b
// ==================================================

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
    
    int n, m;
    cin >> n >> m;

    vector < int > a(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector < int > ans;

    int j=0;
    for(int i=1; i<=n; i++){
        if(j==m){
            ans.push_back(i);
            continue;
        }
        if(a[j]==i){
            j++;
        } else {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }
}
