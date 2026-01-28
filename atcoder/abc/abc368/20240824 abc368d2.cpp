// ==================================================
// Problem   : ABC368_D - Minimum Steiner Tree
// URL       : https://atcoder.jp/contests/abc368/tasks/abc368_d
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

int n, k;
vector < vector <int> > arr;
vector <int> V;
vector <int> visit;

int dfs(int x){
    int ans = 0;
    visit[x-1] = 1;

    int ii = arr[x-1].size();
    for(int i=0; i<ii; i++){
        if(visit[arr[x-1][i]-1] == 1) continue;
        ans += dfs(arr[x-1][i]);
    }

    visit[x-1] = 0;

    if(ans > 0){
        return ans + 1;
    }else if(V[x-1] == 1){
        return 1;
    }else{
        return 0;
    }

    // if(ans == 0){
    //     return 0;
    // }else if(V[x-1] == 1){
    //     return 1;
    // }else{
    //     return ans + 1;
    // }
}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin >> n >> k;

    arr = vector < vector <int> > (n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b);
        arr[b-1].push_back(a);
    }

    // for(int i=0; i<n; i++){
    //     int s = arr[i].size();
    //     for(int j=0; j<s; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    V = vector <int> (n, 0);
    int start;
    for(int i=0; i<k; i++){
        int v;
        cin >> v;
        V[v-1] = 1;

        if(i==0){
            start = v;
        }
    }

    visit = vector <int> (n, 0);
    
    if(k==1){
        cout << 1;
    }else{
        cout << dfs(start);
    }

}
