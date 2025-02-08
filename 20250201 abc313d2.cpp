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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, w;
    cin >> n >> w;

    vector < vector < pair < int, int > > > arr(w);
    // vector < int > start_time_arr(w, 0);
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        // x--;
        // y--;
        arr[x-1].push_back(make_pair(y, i+1));

        // if(y==0){
        //     start_time_arr[x] = 1;
        // }
    }

    for(int i=0; i<w; i++){
        sort(arr[i].begin(), arr[i].end());
    }

    // int start_time = 0;
    // for(int i=0; i<w; i++){
    //     if(start_time_arr[i]==0){
    //         start_time = 1;
    //         break;
    //     }
    // }
    // cout << start_time << endl;

    int min_size = n;
    for(int i=0; i<w; i++){
        if(arr[i].size()<min_size) min_size = arr[i].size();
        // for(auto j: arr[i]){
        //     cout << j << ' ';
        // }cout << endl;
    }
    // cout << min_size << endl;

    vector < int > time(n, -1);
    vector < int > tmp;
    int ma=0;
    for(int t=0; t<min_size; t++){
        tmp.clear();
        for(int j=0; j<w; j++){
            // time[arr[j][t]] = start_time + t;
            tmp.push_back(arr[j][t].second);
            ma = max(ma, arr[j][t].first);
            for(int i=0; i<w; i++){
                time[tmp[i]-1] = ma;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     cout << time[i] << ' ';
    // }cout << endl;

    int q;
    cin >> q;

    int t, a;
    for(int qq=0; qq<q; qq++){
        cin >> t >> a;
        // t--;
        a--;

        // cout << time[a] << ' ' << t << '\t';
        if(time[a]==-1){
            cout << "Yes";
        }else if(time[a]>t){
            cout << "Yes";
        }else{
            cout << "No";
        }
        cout << endl;
    }

}
