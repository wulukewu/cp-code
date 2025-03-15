#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
// #include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, r;
    cin >> n >> r;

    vector < pair <int, int> > arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=0; i<n; i++){
        if(arr[i].first == 1){
            if(r >= 1600 and r <= 2799){
                r += arr[i].second;
            }
        }else{
            if(r >= 1200 and r <= 2399){
                r += arr[i].second;
            }
        }
    }

    cout << r;
}
