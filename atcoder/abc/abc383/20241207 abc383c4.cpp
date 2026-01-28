// ==================================================
// Problem   : ABC383_C - Humidifier 3
// URL       : https://atcoder.jp/contests/abc383/tasks/abc383_c
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

    int h, w, d;
    cin >> h >> w >> d;

    vector < vector < int > > arr(h, vector < int > (w));
    queue < pair < int, pair < int, int > > > q;
    string tt;
    for(int i=0; i<h; i++){
        cin >> tt;
        for(int j=0; j<w; j++){
            if(tt[j]=='#')arr[i][j]=0;
            else if(tt[j]=='.')arr[i][j]=2;
            else if(tt[j]=='H'){
                arr[i][j]=1;
                q.push(make_pair(0, make_pair(i, j)));
            }
        }
    }

    int offset[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int s = q.size();
    while(!q.empty()){
        int i = q.front().second.first;
        int j = q.front().second.second;
        int dd = q.front().first;
        q.pop();

        for(int ij=0; ij<4; ij++){
            int ii = i + offset[ij][0];
            int jj = j + offset[ij][1];

            if(0<=ii and ii<h and 0<=jj and jj<w){
                if(arr[ii][jj]==2 and dd+1<=d){
                    arr[ii][jj]=3;
                    s++;
                    q.push(make_pair(dd+1, make_pair(ii, jj)));
                }
            }
        }
    }

    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << s;
}
