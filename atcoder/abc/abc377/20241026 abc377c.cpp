// ==================================================
// Problem   : ABC377_C - Avoid Knight Attack
// URL       : https://atcoder.jp/contests/abc377/tasks/abc377_c
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
#define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector <int> A(m);
    vector <int> B(m);
    for(int i=0; i<m; i++){
        cin >> A[i] >> B[i];
    }
    
    // for(int i=0; i<m; i++){
    //     cout << A[i] << ' ' << B[i] << endl;
    // }

    set < pair < int, int > > arr;
    int offs1[9] = {2,1,-1,-2,-2,-1,1,2,0};
    int offs2[9] = {1,2,2,1,-1,-2,-2,-1,0};
    for(int i=0; i<m; i++){
        // pair <int, int> arr1;
        // arr1.first = A[i];
        // arr1.second = B[i];
        // arr.insert(arr1);
        for(int j=0; j<9; j++){
            if(A[i]+offs1[j]<=0 or A[i]+offs1[j]>n or B[i]+offs2[j]<=0 or B[i]+offs2[j]>n){continue;}
            // if(A[i]+offs1[j]>0 and A[i]+offs1[j]<=n and B[i]+offs2[j]>0 and B[i]+offs2[j]<=n){
                // cout << A[i]+offs1[j] << ' ' << B[i]+offs2[j] << endl;
                pair <int, int> arr2;
                arr2.first = A[i]+offs1[j];
                arr2.second = B[i]+offs2[j];
                arr.insert(arr2);
            // }
        }
    }

    // set <pair < int, int > > ::iterator it;
    // it = arr.begin();
    // for(int i=0; i<arr.size(); i++){
    //     cout << (*it).first << ' ' << (*it).second << endl;
    //     it++;
    // }

    // cout << arr.size();
    cout << n*n - arr.size();
}
