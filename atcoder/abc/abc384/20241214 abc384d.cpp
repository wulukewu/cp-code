// ==================================================
// Problem   : ABC384_D - Repeated Sequence
// URL       : https://atcoder.jp/contests/abc384/tasks/abc384_d
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, s;
    cin >> n >> s;

    int m = n*2;

    int sum_temp = 0;
    vector < int > A(n);
    vector < int > B(m);
    for(int i=0; i<n; i++) {
        cin >> A[i];
        sum_temp += A[i];
        B[i] = sum_temp;
    }
    int sum = sum_temp;
    for(int i=n; i<m; i++) {
        sum_temp += A[i%n];
        B[i] = sum_temp;
    }

    s %= sum;
    // cout << s << endl;

    int ans = false;

    // for(int i=0; i<m; i++) {
    //     for(int j=i+1; j<m; j++) {
    //         if(B[j] - B[i] == s) {
    //             ans = true;
    //             break;
    //         }
    //     }
    // }

    if(A[0]==s or s==0) {
        ans = true;
    }else{
        int r = 0;
        for(int l=0; l<m; l++) {
            while(r+1<n and B[r+1] - B[l] < s) {
                r++;
            }
            // cout << l << " " << r << endl;
            if(B[r+1] - B[l] == s and (l==0 or (r>=n-1 and l<=n-1))) {
                ans = true;
                break;
            }
        }
    }

    if(ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
