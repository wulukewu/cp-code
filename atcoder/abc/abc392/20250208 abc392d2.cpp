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
    
    int n;
    cin >> n;

    vector < int > k(n);
    vector < map < int, int > > a(n);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            cin >> x;
            a[i][x]++;
        }
    }

    long double max_prob = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long double prob = 0.0;
            for (auto &p : a[i]) {
                if (a[j].count(p.first)) {
                    prob += (long double)p.second / k[i] * (long double)a[j][p.first] / k[j];
                }
            }
            max_prob = max(max_prob, prob);
        }
    }

    cout << fixed << setprecision(15) << max_prob << endl;
    return 0;
}
