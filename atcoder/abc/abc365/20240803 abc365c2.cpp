// ==================================================
// Problem   : ABC365_C - Transportation Expenses
// URL       : https://atcoder.jp/contests/abc365/tasks/abc365_c
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector <int> A(n);
    int a, s=0;
    for(int i=0; i<n; i++){
        cin >> a;
        A[i] = a;
        s += a;
    }
    cout << n << ' ' << m << endl;
    cout << s << endl;

    // sort(A.begin(), A.end());
    for(int i=0; i<n; i++){cout << A[i]<< ' ';}
    cout << endl;

    if(s>m){
        // int x = m-s/n;
        // int x = m;
        int x = s;
        // int x = A[n-1];
        // cout << x << endl;

        int mn;
        while(x>0){
            mn = 0;
            for(int i=0; i<n; i++){
                mn += min(x, A[i]);
            }
            // cout << "mn: " << mn << " x: " << x << endl;
            if(mn <= m){
                // cout << "m: " << m << endl;
                break;
            }

            // if(x==0){
            //     break;
            // }
            x--;
        }
        cout << x;
    }
    else{
        cout << "infinite";
    }

    
}
