// ==================================================
// Problem   : ABC309_E - Family and Insurance
// URL       : https://atcoder.jp/contests/abc309/tasks/abc309_e
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
    vector < pair <int, int> > xy(m);
    vector < int > mx(n, 0);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        xy[i] = make_pair(y, x);
        mx[x-1] = max(mx[x-1], y);
    }
    // sort(xy.begin(), xy.end());

    vector <int> brr(n, -1);
    queue < pair <int, int> > q;
    int ans = 0;
    for(int i=0; i<m; i++){
        x = xy[i].second;
        y = xy[i].first;
        x--;
        q.push(make_pair(x, y));
        while(q.size()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            // cout << x << ' ' << y << endl;

            if(brr[x]==-1){
                brr[x] = y;
                ans++;
            }else if(brr[x]<=y){
                brr[x] = y;
            }else{
                continue;
            }

            if(y-1>=0){
                for(auto j: arr[x]){
                    q.push(make_pair(j, max(y-1, mx[j])));
                }
            }

        }
    }

    // for(auto i: brr){
    //     cout << i << ' ';
    // }
    // cout << endl;
    cout << ans << endl;
}
