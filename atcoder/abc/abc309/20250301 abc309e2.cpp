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

    vector < vector <int> > arr(n);
    int p;
    for(int i=1; i<n; i++){
        cin >> p;
        arr[p-1].push_back(i);
    }

    int x, y;
    set <int> ans;
    vector < int > brr(n, 0);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        brr[x-1] = max(brr[x-1], y);
    }

    queue < pair <int, int> > q;
    q.push(make_pair(0, brr[0]));
    while(q.size()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        // cout << x << ' ' << y << endl;

        // if(brr[x]==0){
        //     brr[x] = y;
        //     ans++;
        // }else if(brr[x]<=y){
        //     brr[x] = y;
        // }else{
        //     continue;
        // }

        if(brr[0]>0){
            ans.insert(0);
        }
        for(auto j: arr[x]){
            if(y-1>=0 or brr[j]>0){
                ans.insert(j);
                q.push(make_pair(j, max(y-1, brr[j])));
            }else{
                q.push(make_pair(j, 0));
            }
        }

    }

    // for(auto i: brr){
    //     cout << i << ' ';
    // }cout << endl;
    // for(auto i: ans){
    //     cout << i << ' ';
    // }cout << endl;

    cout << ans.size() << endl;
}
