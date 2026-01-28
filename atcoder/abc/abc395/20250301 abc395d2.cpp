// ==================================================
// Problem   : ABC395_D - Pigeon Swap
// URL       : https://atcoder.jp/contests/abc395/tasks/abc395_d
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

    int n, q;
    cin >> n >> q;
    
    vector < vector < int > > arr(n);
    vector <int> brr(n);
    for(int i=0; i<n; i++){
        arr[i].push_back(i+1);
        brr[i] = i+1;
    }

    int c, a, b;
    vector <int> tmp;
    for(int i=0; i<q; i++){
        cin >> c;
        if(c==1){
            cin >> a >> b;
            int nest_a = brr[a-1]-1;
            int nest_b = b-1;

            for(int j=0; j<arr[nest_a].size(); j++){
                if(arr[nest_a][j] == a){
                    arr[nest_a].erase(arr[nest_a].begin()+j);
                    break;
                }
            }
            arr[nest_b].push_back(a);
            brr[a-1] = b;
        }else if(c==2){
            cin >> a >> b;
            
            for(int x: arr[a-1]){
                brr[x-1] = b;
            }
            for(int x: arr[b-1]){
                brr[x-1] = a;
            }
            tmp = arr[a-1];
            arr[a-1] = arr[b-1];
            arr[b-1] = tmp;
        }else{
            cin >> a;
            cout << brr[a-1] << endl;
        }
    }
}