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
    
    int n, m;
    cin >> n >> m;

    vector < string > s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    vector < string > t(m);
    for(int i=0; i<m; i++){
        cin >> t[i];
    }

    bool det_break = false;
    int ans_x=-1, ans_y=-1;
    for(int i=0; i<n-m+1; i++){
        for(int j=0; j<n-m+1; j++){

            bool det = true;
            for(int x=0; x<m; x++){
                for(int y=0; y<m; y++){
                    if(s[x+i][y+j] != t[x][y]){
                        det = false;
                        break;
                    }
                }

                if(!det)break;
            }
            if(det){
                ans_x = i+1;
                ans_y = j+1;
                det_break = true;
                break;
            }
        }

        if(det_break)break;
    }

    cout << ans_x << ' ' << ans_y;


}
