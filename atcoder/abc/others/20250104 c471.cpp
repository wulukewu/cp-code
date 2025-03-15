#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
// #include <fstream>

bool cmp(pair < int , int > a, pair < int , int > b) {
    return a.second * b.first < a.first * b.second;
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < pair < int , int > > arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
    }
    for(int i=0; i<n; i++) {
        cin >> arr[i].second;
    }

    // for(int i=0; i<n; i++) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    sort(arr.begin(), arr.end(), cmp);

    // for(int i=0; i<n; i++) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    int ans = 0;
    int up = arr[0].second;
    for(int i=1; i<n; i++) {
        ans += arr[i].first * up;
        up += arr[i].second;
    }

    cout << ans << endl;

}