// ==================================================
// Problem   : ABC372_B - 3^A
// URL       : https://atcoder.jp/contests/abc372/tasks/abc372_b
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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int m;
    cin >> m;
    int n=0;

    vector <int> A;
    bool add=false;
    // for(int b=20; b>=0; b--){
    int b=20;
    while(true){
        if(m>=pow(3, b)){
            add=true;
            m-=pow(3, b);
            A.push_back(b);
            n++;
            b++;
        }
        // else if(add){
        //     A.push_back(0);
        //     n++;
        // }
        if(m==0 or b<0){break;}
        b--;
    }

    cout << n << endl;
    for(int i=0; i<n; i++){
        cout << A[i] << ' ';
    }
    
    
}
