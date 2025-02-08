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

    vector <int> T(n);
    vector <int> V(n);

    for(int i=0; i<n; i++){
        cin >> T[i];
        cin >> V[i];
    }

    int s = V[0];
    int last = T[0];
    for(int i=1; i<n; i++){
        s -= T[i]-last;
        if(s<0) s = 0;
        // cout << s << ' ';
        last = T[i];
        s += V[i];
        // cout << s << endl;
    }

    cout << s << endl;

}
