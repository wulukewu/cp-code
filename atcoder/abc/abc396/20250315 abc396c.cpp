#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
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

    vector < int > b(n);
    for(int i=0; i<n; i++) cin >> b[i];
    vector < int > w(m);
    for(int i=0; i<m; i++) cin >> w[i];

    sort(b.begin(), b.end(), greater < int > ());
    sort(w.begin(), w.end(), greater < int > ());

    for(int i=1; i<n; i++){
        b[i] += b[i-1];
    }
    for(int i=1; i<m; i++){
        w[i] += w[i-1];
    }
    
    // for(int i=0; i<n; i++){
    //     cout << b[i] << ' ';
    // }cout << endl;
    // for(int i=0; i<m; i++){
    //     cout << w[i] << ' ';
    // }cout << endl;

    int ans = 0;
    int max_w = 0;
    for(int i=0; i<n; i++){
        if(i<m){
            max_w = max(max_w, w[i]);
        }
        ans = max(ans, b[i]+max_w);
        // for(int j=0; j<=i; j++){
        //     ans = max(ans, b[i]+w[j]);
        // }
    }

    cout << ans;

}
