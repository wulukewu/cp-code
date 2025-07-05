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

bool solve(){
    int n;
    cin >> n;

    vector < pair < int, int > > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        if(arr[i].first>0){
            arr[i].second = 1;
        }else{
            arr[i].second = -1;
            arr[i].first *= -1;
        }
    }

    bool det = true;
    for(int i=0; i<n-1; i++){
        if(arr[i].first != arr[i+1].first){
            det = false;
            break;
        }
    }

    if(det){
        int b1 = 0;
        int b2 = 0;
        for(int i=0; i<n; i++){
            if(arr[i].second > 0) b1++;
            else b2++;
        }
        if(b1==n or b2==n or abs(b1-b2)<=1) return true;
        else return false;
    }

    sort(arr.begin(), arr.end());
    // for(int i=0; i<n; i++){
    //     cout << arr[i].first << ' ' << arr[i].second << endl;
    // }

    for(int i=0; i<n-2; i++){
        if(arr[i].first*arr[i+2].first != arr[i+1].first*arr[i+1].first){
            return false;
        }
        if(arr[i].second != arr[i+2].second){
            return false;
        }
    }
    return true;
}

signed main() {
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
