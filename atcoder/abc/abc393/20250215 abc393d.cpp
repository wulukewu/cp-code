// ==================================================
// Problem   : ABC393_D - Swap to Gather
// URL       : https://atcoder.jp/contests/abc393/tasks/abc393_d
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

    string s;
    cin >> s;

    int cnt = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            arr.push_back(i);
            cnt++;
        }
    }

    if (cnt <= 1) {
        cout << 0;
    } else {
        int t = arr[0];
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            ans += arr[i] - t;
            t++;
        }

        int j = ans;
        for (int i = 1; i < cnt; i++) {
            j -= (arr[i] - arr[i - 1] - 1) * (cnt - i * 2);
            ans = min(ans, j);
        }
        cout << ans;
    }
}
// signed main() {
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);

//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     // int sum = 0;
//     int cnt = 0;
//     vector < int > arr;
//     for(int i=0; i<n; i++){
//         if(s[i]=='1'){
//             arr.push_back(i);
//             // sum += i;
//             cnt++;
//         }
//     }
//     // sum -= arr[0] * cnt;
//     // cout << sum << " " << cnt << endl;

//     // int j;
//     if(cnt<=1){
//         cout << 0;
//     }else{
//         int t = arr[0];
//         int ans = 0;
//         for(int i=0; i<cnt; i++){
//             ans += arr[i]-t;
//             t++;
//         }
//         // cout << ans;
//         int j=ans;
//         for(int i=0; i<cnt; i++){
//             j -= (arr[i]-arr[i-1]-1)*(cnt-i*2);
//             ans = min(ans, j);
//         }
//         cout << ans;
//         // int ans = 0;
//         // int mid = (arr[0]+arr[cnt-1])/2;
//         // for(int i=mid-cnt/2, j=0; j<cnt; i++, j++){
//         //     ans += abs(arr[j]-i);
//         // }
//         // cout << ans;
//         // int ans = sum - cnt*(cnt-1)/2;
//         // cout << ans;
//     }


//     // int m = arr.size();
//     // int mid = (arr[0]+arr[m-1])/2;
//     // int left_cnt = 0;
//     // int right_cnt = 0;
//     // for(int i=0; i<m-1; i++){
//     //     if(arr[i]<mid){
//     //         left_cnt++;
//     //     }else if(arr[i]>mid){
//     //         right_cnt++;
//     //     }
//     // }

//     // int ans = 0;

//     // int ans, mid;
//     // if(cnt%2==0){
//     //     mid = (arr[cnt/2-1]+arr[cnt/2])/2-1;
//     //     ans = sum - mid * cnt;
//     //     cout << ans;
//     // }else{
//     //     mid = arr[cnt/2];
//     //     ans = sum - (mid-1) * (cnt-1);
//     //     cout << ans;
//     // }

//     // int ans, mid;
//     // if(cnt%2==0){
//     //     ans = 0;
//     //     mid = (arr[cnt/2-1]+arr[cnt/2])/2;
//     //     for(int i=mid-cnt/2, j=0; j<cnt; i++, j++){
//     //         // cout << i << " " << arr[j] << endl;
//     //         ans += abs(arr[j]-i);
//     //     }
//     //     cout << ans;
//     //     // ans = sum - mid * cnt;
//     //     // cout << ans;
//     // }else{
//     //     ans = 0;
//     //     mid = arr[cnt/2];
//     //     for(int i=mid-cnt/2, j=0; j<cnt; i++, j++){
//     //         // cout << i << " " << arr[j] << endl;
//     //         ans += abs(arr[j]-i);
//     //     }
//     //     cout << ans;
//     // }
    
// }
