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
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector < vector < int > > arr(n);

    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);
    }

    vector < int > visited(n, 0);
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            components++;
            queue < int > q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty()) {
                int current = q.front();
                q.pop();

                for (int neighbor : arr[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    int result = m - (n - components);
    cout << result << endl;

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<arr[i].size(); j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // vector < int > brr(n, -1);
    // vector < int > crr;
    // int ans = 0;
    // int k;
    // for(int i=0; i<n; i++){
    //     stack < pair < int, vector < int > > > togo;
    //     if(brr[i]==-1){
    //         crr.clear();
    //         togo.push(make_pair(i, crr));
    //     }

    //     while(!togo.empty()){
    //         k = togo.top().first;
    //         crr = togo.top().second;
    //         togo.pop();
    //         for(int j=0; j<arr[k].size(); j++){
    //             if(brr[j]==-1){
    //                 crr.push_back(j);
    //                 togo.push(make_pair(j, crr));
    //                 brr[j] = 0;
    //             }else if(brr[j]==0){
    //                 ans++;
    //                 for(int l=0; l<crr.size(); l++){
    //                     brr[l] = 1;
    //                 }
    //             }else if(brr[j]==1){}
    //         }
    //     }

    // }

    // for(int i=0; i<n; i++){
    //     cout << brr[i] << ' ';
    // }
    // cout << endl;

    // cout << ans;

    // vector < int > brr(n, 0);
    // int ans = 0;
    // bool break_check;
    // while(true){
    //     break_check = true;
    //     queue < int > togo;
    //     for(int i=0; i<n; i++){
    //         if(brr[i]==0){
    //             break_check = false;
    //             for(int j=0; j<arr[i].size(); j++){
    //                 togo.push(arr[i][j]);
    //             }
    //             brr[i] = 1;
    //         }else{
    //             ans++;
    //         }
    //     }

    //     if(break_check)break;
    // }

    // cout << ans;
}
