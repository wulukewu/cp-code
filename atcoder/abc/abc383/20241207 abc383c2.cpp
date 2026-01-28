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
#include <fstream>

int h, w, d;
vector < vector < int > > arr;
vector < pair < int, int > > hums;
string t;
vector < pair < int, int > > steps;

signed bfs(int i, int j, int dd){
    // steps.erase(steps.begin());
    if(dd+1>d) return 0;

    // up
    if(i-1>=0){
        bool det = false;
        for(int k=0; k<steps.size(); k++){
            if(steps[k].first==i-1 and steps[k].second==j){
                det = true;
                break;
            }
        }

        if(arr[i-1][j] == 0 and !det){
            arr[i-1][j] = 3;
            steps.push_back(make_pair(i-1, j));
            bfs(i-1, j, dd+1);
        }

        steps.push_back(make_pair(i-1, j));
    }

    // down
    if(i+1<h){
        bool det = false;
        for(int k=0; k<steps.size(); k++){
            if(steps[k].first==i+1 and steps[k].second==j){
                det = true;
                break;
            }
        }

        if(arr[i+1][j] == 0 and !det){
            arr[i+1][j] = 3;
            steps.push_back(make_pair(i+1, j));
            bfs(i+1, j, dd+1);
        }

        steps.push_back(make_pair(i+1, j));
    }

    // left
    if(j-1>=0){
        bool det = false;
        for(int k=0; k<steps.size(); k++){
            if(steps[k].first==i and steps[k].second==j-1){
                det = true;
                break;
            }
        }

        if(arr[i][j-1] == 0 and !det){
            arr[i][j-1] = 3;
            steps.push_back(make_pair(i, j-1));
            bfs(i, j-1, dd+1);
        }

        steps.push_back(make_pair(i, j-1));
    }

    // right
    if(j+1<w){
        bool det = false;
        for(int k=0; k<steps.size(); k++){
            if(steps[k].first==i and steps[k].second==j+1){
                det = true;
                break;
            }
        }

        if(arr[i][j+1] == 0 and !det){
            arr[i][j+1] = 3;
            steps.push_back(make_pair(i, j+1));
            bfs(i, j+1, dd+1);
        }

        steps.push_back(make_pair(i, j+1));
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

        // steps.push_back(make_pair(i, j));
        bfs(i, j, 1);
    }

    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << s;
}
