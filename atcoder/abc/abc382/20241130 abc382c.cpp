// ==================================================
// Problem   : ABC382_C - Kaiten Sushi
// URL       : https://atcoder.jp/contests/abc382/tasks/abc382_c
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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector <int> A(n);
    vector <int> B(m);

    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<m; i++){
        cin >> B[i];
    }

    int mi = 2e5+1;
    vector < pair<int, int> > arr;
    for(int i=0; i<n; i++){
        if(A[i]<mi){
            arr.push_back(make_pair(A[i], i+1));
            mi = A[i];
        }
    }

    reverse(arr.begin(), arr.end());
    int nm = arr.size();
    // for(int i=0; i<nm; i++){
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    for(int j=0; j<m; j++){

        if(B[j]<arr[0].first){
            cout << -1 << endl;
            continue;
        }

        int l = 0;
        int r = nm;
        while(r-l>1){
            int mid = (l+r)/2;
            if(arr[mid].first<=B[j]){
                l = mid;
            }else{
                r = mid;
            }
            // cout << l << " " << r << " " << mid << endl;
        }
        cout << arr[l].second << endl;
    }
}
