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
    
    int n;
    cin >> n;

    vector < vector < int > > arr(n, vector < int > (n, 0));
    vector < int > R(n, 0);
    vector < int > C(n, 0);

    for(int i=0; i<n; i++){
        string st;
        cin >> st;

        for(int j=0; j<n; j++){
            if(st[j]=='o'){
                arr[i][j] = 1;
                R[i] += 1;
                C[j] += 1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for(int i=0; i<n; i++){
    //     cout << R[i] << ' ';
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     cout << C[i] << ' ';
    // }
    // cout << endl;

    int s=0;
    for(int i=0; i<n; i++){
        s += R[i];
    }
    // cout << s << endl;

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                // cout << i << ' ' << j << ' ' << ans << endl;
                continue;
            }
            // ans += max((R[i]-1)*(C[j]-1), 0);
            ans += (R[i]-1)*(C[j]-1);
            // cout << i << ' ' << j << ' ' << ans << endl;
        }
    }

    cout << ans;

}
