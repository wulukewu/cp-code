// ==================================================
// Problem   : ABC366_C - Balls and Bag Query
// URL       : https://atcoder.jp/contests/abc366/tasks/abc366_c
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int q;
    cin >> q;

    int s=0;
    int action;
    int x;
    vector <int> arr(1000010, 0);
    for(int i=0; i<q; i++){
        cin >> action;
        if(action == 1){
            cin >> x;
            if(arr[x-1]==0){
                arr[x-1]++;
                s++;
            }else{
                arr[x-1]++;
            }
        }else if(action == 2){
            cin >> x;
            if(arr[x-1]==1){
                arr[x-1]--;
                s--;
            }else{
                arr[x-1]--;
            }
        }else{
            cout << s << endl;
        }
    }
}
