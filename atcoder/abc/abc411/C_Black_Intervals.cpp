// ==================================================
// Problem   : ABC411_C - Black Intervals
// Limits    : 3 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc411/tasks/abc411_c
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
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;
    
    vector < int > arr(n, 0);

    int a;
    int ans = 0;
    for(int i=0; i<q; i++){
        cin >> a;
        a--;

        if(arr[a]==0){
            arr[a]=1;
            if(a==0){
                if(arr[a+1]==0){
                    ans++;
                }
            }else if(a==n-1){
                if(arr[a-1]==0){
                    ans++;
                }
            }else{
                if(arr[a-1]==1 and arr[a+1]==1){
                    ans--;
                }else if(arr[a-1]==0 and arr[a+1]==0){
                    ans++;
                }
            }
        }else{
            arr[a]=0;
            if(a==0){
                if(arr[a+1]==0){
                    ans--;
                }
            }else if(a==n-1){
                if(arr[a-1]==0){
                    ans--;
                }
            }else{
                if(arr[a-1]==0 and arr[a+1]==0){
                    ans--;
                }else if(arr[a-1]==1 and arr[a+1]==1){
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}
