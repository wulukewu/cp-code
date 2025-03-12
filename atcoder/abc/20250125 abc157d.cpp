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
    
    int n, m, k;
    cin >> n >> m >> k;

    vector < vector < int > > friendship(n);
    vector < vector < int > > blockship(n);
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
    for(int i=0; i<k; i++){
        cin >> a >> b;
        a--;
        b--;
        blockship[a].push_back(b);
        blockship[b].push_back(a);
    }

    // for(auto x: friendship){
    //     for(auto y: x){
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(auto x: blockship){
    //     for(auto y: x){
    //         cout << y << ' ';
    //     }
    //     cout << endl;
    // }

    vector < int > ans(n, 0);

    queue < int > q;
    set < int > s;
    vector < int > went(n, 0);
    int t, u, now;
    for(int i=0; i<n; i++){
        if(went[i]==1)continue;
        s.clear();
        q.push(i);
        s.insert(i);
        went[i] = 1;
        while(!q.empty()){
            t = q.front();
            // cout << t << endl;
            q.pop();
            u = friendship[t].size();
            for(int j=0; j<u; j++){
                now = friendship[t][j];
                if(went[now]==0){
                    went[now] = 1;
                    q.push(now);
                    s.insert(now);
                }
            }
        }

        for(auto x: s){
            ans[x] = s.size()-1;
            for(auto y: friendship[x]){
                if(s.find(y)!=s.end()){
                    ans[x]--;
                }
            }
            for(auto y: blockship[x]){
                if(s.find(y)!=s.end()){
                    ans[x]--;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }


}
