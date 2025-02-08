#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector < vector < vector <int> > > arr(n, vector < vector <int> > (n, vector < int > (n, 0)));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cin >> arr[i][j][k];
            }
        }
    }

    int q;
    cin >> q;
    for(int qq=0; qq<q; qq++){
        int lx, rx, ly, ry, lz, rz;
        cin>>lx>>rx>>ly>>ry>>lz>>rz;

        int s=0;
        // for(int i=min(lx, rx); i<(max(lx, rx)+1); i++){
        //    for(int j=min(ly, ry); j<(max(ly, ry)+1); j++) {
        //     for(int k=min(lz, rz); k<(max(lz, rz)+1); k++){
        //         s += arr[i-1][j-1][k-1];
        //     }
        //    }
        // }
        for(int i=lx; i<(rx+1); i++){
           for(int j=ly; j<(ry+1); j++) {
            for(int k=lz; k<(rz+1); k++){
                s += arr[i-1][j-1][k-1];
            }
           }
        }
        cout << s << endl;
    }

}
