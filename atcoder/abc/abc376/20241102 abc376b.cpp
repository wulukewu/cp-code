// ==================================================
// Problem   : ABC376_B - Hands on Ring (Easy)
// URL       : https://atcoder.jp/contests/abc376/tasks/abc376_b
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
    
    int n, q;
    cin >> n >> q;

    vector < char > H(q);
    vector < int > T(q);
    for(int i=0; i<q; i++) {
        cin >> H[i] >> T[i];
    }

    int l = 1;
    int r = 2;
    int ans = 0;

    for(int i=0; i<q; i++) {
        if(H[i] == 'R'){
            // cout << (l-r+n)%n << " " << (T[i]-r+n)%n << ' ';
            if(T[i] == r){
                continue;
            }else if((l-r+n)%n > (T[i]-r+n)%n){
                ans += (T[i]-r+n)%n;
            }else if((l-r+n)%n < (T[i]-r+n)%n){
                ans += n-(T[i]-r+n)%n;
            }
            r = T[i];
        }else{
            // cout << (r-l+n)%n << " " << (T[i]-l+n)%n << ' ';
            if(T[i] == l){
                continue;
            } else if((r-l+n)%n < (T[i]-l+n)%n){
                ans += (l-T[i]+n)%n;
            }else if((r-l+n)%n > (T[i]-l+n)%n){
                ans += n-(l-T[i]+n)%n;
            }
            l = T[i];
        }
        // cout << ans << endl;
    }

    cout << ans;

}
