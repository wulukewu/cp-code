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

    vector <int> X(n+1, 0);
    vector <int> Y(n+1, 0);


    for(int i=0; i<n; i++){
        cin >> X[i] >> Y[i];
    }

    int x = 0;
    int y = 0;
    double ans = 0;

    for(int i=0; i<n+1; i++){
        ans += sqrt(pow(X[i]-x, 2) + pow(Y[i]-y, 2));
        x = X[i];
        y = Y[i];
    }

    printf("%.7f", ans);
    
}
