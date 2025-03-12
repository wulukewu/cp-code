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
    
    int h, w;
    cin >> h >> w;

    // black
    int min_x = w;
    int max_x = -1;
    int min_y = h;
    int max_y = -1;

    string s;
    vector < vector < int > > arr(h, vector < int > (w));
    for(int i=0; i<h; i++){
        cin >> s;
        for(int j=0; j<w; j++){
            if(s[j]=='.'){
                arr[i][j] = 0;
            }else if(s[j]=='#'){
                arr[i][j] = 1;
                min_x = min(min_x, j);
                max_x = max(max_x, j);
                min_y = min(min_y, i);
                max_y = max(max_y, i);
            }else{
                arr[i][j] = 2;
            }
        }
    }

    // cout << min_x << " " << max_x << " " << min_y << " " << max_y << endl;

    bool det = true;
    for(int i=min_y; i<=max_y; i++){
        for(int j=min_x; j<=max_x; j++){
            if(arr[i][j]==0){
                det = false;
                break;
            }
        }
    }

    if(det){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
