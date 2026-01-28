// ==================================================
// Problem   : ABC370_D - Cross Explosion
// URL       : https://atcoder.jp/contests/abc370/tasks/abc370_d
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
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int h, w, q;
    cin >> h >> w >> q;

    vector < int > R(q);
    vector < int > C(q);
    int r, c;
    for(int i=0; i<q; i++){
        cin >> r >> c;
        R[i] = r;
        C[i] = c;
    }

    // vector < int > H(h, 0);
    // vector < int > W(w, 0);
    // vector < vector <int> > arr(h, vector <int> (w, 0));
    // for(int i=0; i<q; i++){
    //     if(arr[R[i]-1][C[i]-1]==0 and !(H[i]==1 and W[i]==1)){
    //         arr[R[i]-1][C[i]-1] = 1;
    //     }
    // }

    int ans = h*w;

    vector < vector <int> > arr(h, vector <int> (w, 1));
    for(int i=0; i<q; i++){
        if(arr[R[i]-1][C[i]-1]==1){
            arr[R[i]-1][C[i]-1]=0;
            ans--;
        }else{
            // up
            r = R[i]-1;
            c = C[i]-1;
            while(r>0){
                r--;
                if(arr[r][c]==1){
                    arr[r][c] = 0;
                    ans--;
                    break;
                }
            }

            // down
            r = R[i]-1;
            c = C[i]-1;
            while(r<h-1){
                r++;
                if(arr[r][c]==1){
                    arr[r][c] = 0;
                    ans--;
                    break;
                }
            }
            
            // left
            r = R[i]-1;
            c = C[i]-1;
            while(c>0){
                c--;
                if(arr[r][c]==1){
                    arr[r][c] = 0;
                    ans--;
                    break;
                }
            }

            // right
            r = R[i]-1;
            c = C[i]-1;
            while(c<w-1){
                c++;
                if(arr[r][c]==1){
                    arr[r][c] = 0;
                    ans--;
                    break;
                }
            }
        }

        // for(int j=0; j<h; j++){
        //     for(int k=0; k<w; k++){
        //         cout << arr[j][k] << ' ';
        //     }
        //     cout << endl;
        // }
    }

    cout << ans;

}
