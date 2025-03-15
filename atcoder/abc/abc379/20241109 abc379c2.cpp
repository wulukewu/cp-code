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
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector < int > X(m);
    vector < int > A(m);

    for(int i=0; i<m; i++) {
        cin >> X[i];
    }

    int s = 0;
    for(int i=0; i<m; i++) {
        cin >> A[i];
        s += A[i];
    }
    
    if(s != n) {
        cout << -1;
        exit(0);
    }

    vector < pair < int, int > > arr(m);
    for(int i=0; i<m; i++) {
        arr[i] = make_pair(X[i], A[i]);
    }
    sort(arr.begin(), arr.end());

    // for(int i=0; i<m; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << endl;
    // }

    if(arr[0].first != 1) {
        cout << -1;
        exit(0);
    }

    int ans = 0;
    int count = 0;
    for(int i=0; i<m; i++){
        if(count + 1 < arr[i].first){
            cout << -1;
            exit(0);
        }
        ans += arr[i].second * (arr[i].first-1);
        count += arr[i].second;
    }

    ans = n*(n-1)/2 - ans;
    cout << ans;
}
