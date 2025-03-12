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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector < int > A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    for(int i=n-k; i<n; i++){
        cout << A[i] << ' ';
    }
    for(int i=0; i<n-k; i++){
        cout << A[i] << ' ';
    }
}
