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

int h, w, d;
vector < vector < int > > arr;
vector < pair < int, int > > hums;
string t;

signed dfs(int i, int j, int dd){
    if(dd+1>d) return 0;

    // up
    if(i-1>=0){
        if(arr[i-1][j] == 0){
            arr[i-1][j] = 3;
            dfs(i-1, j, dd+1);
        }
    }

    // down
    if(i+1<h){
        if(arr[i+1][j] == 0){
            arr[i+1][j] = 3;
            dfs(i+1, j, dd+1);
        }
    }

    // left
    if(j-1>=0){
        if(arr[i][j-1] == 0){
            arr[i][j-1] = 3;
            dfs(i, j-1, dd+1);
        }
    }

    // right
    if(j+1<w){
        if(arr[i][j+1] == 0){
            arr[i][j+1] = 3;
            dfs(i, j+1, dd+1);
        }
    }
}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> h >> w >> d;

    arr = vector < vector < int > > (h, vector < int > (w, 0));
    hums = vector < pair < int, int > > ();

    for(int i=0; i<h; i++){
        cin >> t;
        for(int j=0; j<w; j++){
            if(t[j] == '#')arr[i][j] = 1;
            else if(t[j] == '.') arr[i][j] = 0;
            else{
                arr[i][j] = 2;
                hums.push_back(make_pair(i, j));
            }
        }
    }
    
    int s=hums.size();
    for(int ij=0; ij<s; ij++){
        int i = hums[ij].first;
        int j = hums[ij].second;

        dfs(i, j, 0);
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(arr[i][j]==3) s++;
        }
    }

    cout << s;
}
