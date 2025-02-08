#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <unordered_map>
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

    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    unordered_map<int, vector<int> > arr;
    for(int i = 0; i < n; i++) {
        arr[A[i] - 1].push_back(i + 1);
    }

    for(int i = 0; i < n; i++) {
        int m = arr[A[i] - 1].size();
        if(m == 0) {
            cout << -1 << ' ';
        } else {
            int ans = -1;
            for(int j = 0; j < m; j++) {
                if(arr[A[i] - 1][j] < i + 1) {
                    ans = arr[A[i] - 1][j];
                }
            }
            cout << ans << ' ';
        }
    }
    cout << endl;
}