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

    vector <int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector < vector < int > > arr(pow(10, 6));
    for(int i=0; i<n; i++){
        arr[A[i]-1].push_back(i);
    }

    int ans = -1;
    for(int i=0; i<pow(10, 6); i++){
        if(arr[i].size()>=2){
            // for(int j=1; j<arr[i].size(); j++){
            //     cout << arr[i][j] << ' ' << arr[i][j-1] << endl;
            // }cout << endl;
                
            if(ans==-1){
                ans = arr[i][1]-arr[i][0]+1;
            }
            for(int j=1; j<arr[i].size(); j++){
                ans = min(ans, arr[i][j]-arr[i][j-1]+1);
            }
        }    
    }
    cout << ans;

}
