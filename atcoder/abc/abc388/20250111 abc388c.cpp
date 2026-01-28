// ==================================================
// Problem   : ABC388_C - Various Kagamimochi
// URL       : https://atcoder.jp/contests/abc388/tasks/abc388_c
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
    
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int max = A[n-1];

    int j = 0;
    int sum = 0;

    for(int i=0; i<n; i++){
        while(j<n and A[j]<A[i]*2){
            j++;
        }
        sum += n-j;
        if(A[i]*2>max) break;
        // cout << n-j << endl;
    }
    cout << sum;



    // sort(A.begin(), A.end());

    // int max = A[n-1];

    // vector < int > arr(max+1, -1);

    // for(int j=0; j<n; j++){
    //     cout << ceil(A[j]/2.0) << ' ';
    // } cout << endl;

    // int j=0;
    // for(int i=1; i<max+1; i++){
    //     // while(j<n and i*2>A[j]){
    //     //     j++;
    //     //     k--;
    //     // }
    //     while(true){
    //         if(j==n) break;
    //         if(A[j]<i*2){
    //             j++;
    //         // } else if(A[j]==i*2){
    //         //     j++;
    //         //     break;
    //         } else {
    //             break;
    //         }
    //     }
    //     A[i] = n-j;
    //     cout << A[i] << ' ';
    // }
    
    // int j=0, k=0;
    // for(int i=1; i<max+1; i++){
    //     while(j<n and ceil(A[j]/2.0)<=i){
    //         j++;
    //         k++;
    //     }
    //     arr[i] = n-k;
    //     cout << arr[i] << ' ';
    // }
    // cout << endl;

    // int ans = 0;
    // for(int i=0; i<n-1; i++){
    //     ans += arr[ceil(A[i]/2.0)];
    // }
    // cout << ans << endl;


    // int ans = 0;
    // int min, idx;
    // for(int i=0; i<n-1; i++){
    //     min = A[i]*2;
    //     idx = -1;
    //     for(int j=i+1; j<n; j++){
    //         if(A[j]>=min){
    //             idx = n-j;
    //             break;
    //         }
    //     }
    //     if(idx!=-1){
    //         ans += idx;
    //     }
    // }
    // cout << ans << endl;
}
