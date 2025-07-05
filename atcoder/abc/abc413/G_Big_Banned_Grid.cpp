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
    int h, w, k;
    cin >> h >> w >> k;

    set < pair < int, int > > arr;
    int r, c;
    for(int i=0; i<k; i++){
        cin >> r >> c;
        r--; c--;
        arr.insert(make_pair(r, c));
    }

    queue < pair < int, int > > q;
    for(auto i: arr){
        if(i.first == 0 or i.second == w-1){
            q.push(i);
        }
    }

    set < pair < int, int > > visit;
    int offs[8][2] = {{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
    int x, y;
    bool ans = false;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        // cout << t.first << ' ' << t.second << endl;

        if(t.first==h-1 or t.second == 0){
            ans = true;
            break;
        }

        for(int i=0; i<8; i++){
            x = t.first + offs[i][0];
            y = t.second + offs[i][1];
            if(!(0<=x and x<h and 0<=y and y<w)) continue;

            auto p = make_pair(x, y);
            if(arr.find(p)!=arr.end() and visit.find(p)==visit.end()){
                q.push(p);
                visit.insert(p);
            }
        }
    }

    if(ans){
        cout << "No";
    }else{
        cout << "Yes";
    }
}
