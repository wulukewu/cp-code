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
    
    int n, q;
    cin >> n >> q;

    vector < int > arra(n);
    for(int i=0; i<n; i++){
        arra[i] = i;
    }
    vector < int > arrb(n, 1);
    int ans = 0;

    int t, p, h;
    for(int i=0; i<q; i++){
        cin >> t;
        if(t==1){
            cin >> p >> h;
            p--;
            h--;

            if(arrb[arra[p]]==2) ans--;
            if(arrb[h]==1) ans++;

            arrb[arra[p]]--;
            arra[p] = h;
            arrb[h]++;

        }else{
            cout << ans << endl;
        }

        // for(int j=0; j<n; j++){
        //     cout << arra[j] << ' ';
        // }cout << endl;
        // for(int j=0; j<n; j++){
        //     cout << arrb[j] << ' ';
        // }cout << endl;
        // cout << endl;
    }

    // for(int i=0; i<q; i++){
    //     cin >> t;
    //     if(t==1){
    //         cin >> p >> h;

    //         if(arr[p-1]==0)continue;

    //         if(arr[h-1]>1) ans--;
    //         arr[h-1]++;
    //         if(arr[h-1]>1) ans++;

    //         if(arr[p-1]>1) ans--;
    //         arr[p-1]--;
    //         if(arr[p-1]>1) ans++;

    //         for(int j=0; j<n; j++){
    //             cout << arr[j] << ' ';
    //         }
    //         cout << endl;

    //     }else{
    //         cout << ans << endl;
    //     }
    // }
}
