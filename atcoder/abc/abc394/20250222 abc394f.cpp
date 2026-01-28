// ==================================================
// Problem   : ABC394_F - Alkane
// URL       : https://atcoder.jp/contests/abc394/tasks/abc394_f
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
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

int n;
vector < vector < int > > arr;
int a, b;
set < int > greater4;

signed dfs(int v, vector < int > visited){
    visited[v] = 1;
    for(auto i: greater4){
        if(visited[i]==0){
            dfs(i, visited);
        }
    }

    for(int i=0; i<n; i++){
        if(visited[i]==1){
            for(auto j: arr[i]){
                if(visited[j]==0 and arr[j].size()==1){
                    visited[j] = 1;
                    dfs(j, visited);
                    visited[j] = 0;
                }
            }
        }
    }

}

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n;

    vector < vector < int > > arr(n);

    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        a--; b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        if(arr[i].size()>=4){
            greater4.insert(i);
        }
        cout << arr[i].size() << " ";
    }
    cout << endl;

    for(auto i: greater4, vector < int > (n, 0)){
        dfs(i);
    }
}
