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

    vector < vector < int > > arr(m);
    vector < vector < int > > ans(n);

    int k, a;
    for(int i=0; i<m; i++){
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> a;
            arr[i].push_back(a);
            ans[a-1].push_back(i);
        }
    }

    vector < int > v(m, 0);
    int x = 0;
    for(int i=0; i<m; i++){
        v[i] = arr[i].size();
        if(v[i]==0){
            x++;
        }
    }

    int b;
    for(int i=0; i<n; i++){
        cin >> b;
        for(int j=0; j<ans[b-1].size(); j++){
            v[ans[b-1][j]]--;
            if(v[ans[b-1][j]]==0){
                x++;
            }
        }
        cout << x << endl;
    }

    // vector < int > k(m);
    // vector < vector < int > > arr(m, vector < int > (n, 0));

    // int a;
    // for(int i=0; i<m; i++){
    //     cin >> k[i];

    //     for(int j=0; j<k[i]; j++){
    //         cin >> a;
    //         arr[i][a-1] = 1;
    //     }
    // }

    // // for(int i=0; i<m; i++){
    // //     cout << k[i] << ' ';
    // // }
    // // cout << endl;

    // // for(int i=0; i<m; i++){
    // //     for(int j=0; j<n; j++){
    // //         cout << arr[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // }

    // int b;
    // int ans = 0;
    // for(int i=0; i<n; i++){
    //     cin >> b;

    //     for(int j=0; j<m; j++){
    //         if(arr[j][b-1]==0){
    //             continue;
    //         }else{
    //             arr[j][b-1] = 0;
    //             k[j]--;
    //             if(k[j]==0){
    //                 ans++;
    //             }
    //         }
    //     }

    //     cout << ans << endl;
    // }
}
