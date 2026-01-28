// ==================================================
// Problem   : ABC383_B - Humidifier 2
// URL       : https://atcoder.jp/contests/abc383/tasks/abc383_b
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

    vector < vector < int > > arr(h, vector < int > (w, 0));

    string t;
    for(int i=0; i<h; i++){
        cin >> t;
        for(int j=0; j<w; j++){
            if(t[j] == '#') arr[i][j] = 1;
        }
    }

    int idx;
    int ans = 0;
    int dist1, dist2;
    for(int i1=0; i1<h; i1++){
        for(int j1=0; j1<w; j1++){
            if(arr[i1][j1]==0){
                arr[i1][j1] = 2;

                for(int i2=0; i2<h; i2++){
                    for(int j2=0; j2<w; j2++){
                        if(arr[i2][j2]==0){
                            arr[i2][j2] = 2;

                            idx = 0;

                            for(int i=0; i<h; i++){
                                for(int j=0; j<w; j++){
                                    dist1 = abs(i1-i) + abs(j1-j);
                                    dist2 = abs(i2-i) + abs(j2-j);
                                    // cout << dist1 << ' ' << dist2 << endl;
                                    if(arr[i][j]!=1 and (dist1<=d or dist2<=d)){
                                        // cout << i << ' ' << j << endl;
                                        idx++;
                                    }
                                }
                            }

                            // cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << ' ' << idx << endl;
                            ans = max(ans, idx);

                            arr[i2][j2] = 0;
                        }
                    }
                }

                arr[i1][j1] = 0;
            }
        }
    }

    cout << ans << endl;
}
