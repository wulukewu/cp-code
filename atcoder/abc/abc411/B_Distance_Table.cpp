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
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int n;
    cin >> n;

    vector < int > arr(n, 0);
    for(int i=1; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i++){
        arr[i+1] += arr[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout << arr[j] - arr[i] << ' ';
        }
        cout << endl;
    }
}
