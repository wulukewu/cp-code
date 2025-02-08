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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    vector < int > A (n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector < int > arr(n-1);
    for(int i=0; i<n-1; i++){
        arr[i] = A[i+1]-A[i];
    }
    for(int i=0; i<n-1; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;

    int c = 1;
    int ans = n+n-1;
    for(int i=1; i<n-1; i++){
        cout << i << c << ans << endl;
        if(arr[i-1]==arr[i]){
            c += 1;
        }else{
            if(c>=2){
                ans += (c+1-1)*(c+1-2)/2;
            }
            c = 1;
        }
    }
    cout << ans;

    /*
    int ans;
    ans = n + n-1;

    for(int lr=2; lr<n; lr++){
        for(int l=0; l+lr<n; l++){
            int r = l+lr;
            int d = A[l+1]-A[l];
            bool det = true;
            for(int i=l+1; i<r; i++){
                if(A[i+1]-A[i]!=d){
                    det = false;
                    break;
                }
            }
            if(det){
                ans++;
                // cout << "(" << l << "," << r << "): " << ans << endl;
            }
        }
    }

    cout << ans;
    */
}
