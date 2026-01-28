// ==================================================
// Problem   : ABC364_C - Minimum Glutton
// URL       : https://atcoder.jp/contests/abc364/tasks/abc364_c
// ==================================================

#include <iostream>
#include <fstream>
#include <vector>
#define int long long
using namespace std;

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, X, Y;
    cin >> n >> X >> Y;

    vector <int> A(n,-1);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    vector <int> B(n,-1);
    for(int i=0; i<n; i++){
        cin >> B[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << A[i] << ' ';
    // }
    // for(int i=0; i<n; i++){
    //     cout << B[i] << ' ';
    // }
    // cout << endl;

    int x=0;
    int y=0;
    int ans=0;
    for(int i=0; i<n; i++){
        // cout << x << ' ' << y << endl;
        ans++;
        if(not(X<A[i]+x or Y<B[i]+y)){
            x += A[i];
            y += B[i];
            // cout << x << ' ' << y << endl;
        }else{
            if(X==x or Y==y){ans++;}
            // cout << "break" << endl;
            ans--;
            break;
        }
    }

    cout << ans;
}
