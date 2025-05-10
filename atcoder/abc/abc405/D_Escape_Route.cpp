#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#define int long long
// #define float double
// #define float long double
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    
    pair < int, int > xy;
    vector < vector < char > > s(h, vector < char > (w));
    queue < pair < int, int > > q;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> s[i][j];
            if(s[i][j]=='E'){
                xy = make_pair(i, j);
                q.push(xy);
            }
        }
    }

    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char dirsym[4] = {'^', '<', 'v', '>'};

    int x, y;
    while(!q.empty()){
        xy = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            x = xy.first + dir[i][0];
            y = xy.second + dir[i][1];

            if(x>=0 and x<h and y>=0 and y<w){
                if(s[x][y]=='.'){
                    s[x][y] = dirsym[i];
                    q.push(make_pair(x, y));
                }
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
}
