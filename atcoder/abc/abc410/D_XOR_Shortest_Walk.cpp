// ==================================================
// Problem   : ABC410_D - XOR Shortest Walk
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc410/tasks/abc410_d
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
    int n, m;
    cin >> n >> m;

    vector < vector < pair < int, int > > > arr(n);
    int a, b, w;
    for(int i=0; i<m; i++){
        cin >> a >> b >> w;
        arr[a-1].push_back(make_pair(b, w));
        // arr[b-1].push_back(make_pair(a, w));
    }

    queue < pair < int, int > > q;
    pair < int, int > p;
    q.push(make_pair(1, 0));
    vector < set < int > > v(n);
    v[0].insert(0);
    while(!q.empty()){
        p = q.front();
        q.pop();

        // cout << p.first << ' ' << p.second << endl;

        for(auto i: arr[p.first-1]){
            if(v[i.first-1].find(p.second ^ i.second) != v[i.first-1].end()){
                continue;
            }

            q.push(make_pair(i.first, p.second ^ i.second));
            v[i.first-1].insert(p.second ^ i.second);
        }
    }

    // for(int i=0; i<n; i++){
    //     for(auto j: v[i]){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    if(v[n-1].empty()){
        cout << -1;
    }else{
        int ans = 1e8;
        for(auto i: v[n-1]){
            ans = min(ans, i);
        }
        cout << ans;
    }
}
