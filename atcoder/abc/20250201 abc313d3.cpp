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

    int n, w;
    cin >> n >> w;

    vector < vector < pair < int, int> > > arr(w);
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        x--;
        y--;
        arr[x].push_back(make_pair(y, i));
    }

    for(int i=0; i<w; i++){
        sort(arr[i].begin(), arr[i].end());
    }

    int min_size = n;
    for(int i=0; i<w; i++){
        if(arr[i].size()<min_size) min_size = arr[i].size();
        // for(auto j: arr[i]){
        //     cout << j << ' ';
        // }cout << endl;
    }
    // cout << min_size << endl;

    vector < int > time(n, -1);
    int m = 0;
    for(int i=0; i<min_size; i++){
        for(int j=0; j<w; j++){
            m = max(arr[j][i].first, m);
        }

        for(int j=0; j<w; j++){
            time[arr[j][i].second] = m;
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
        t--;
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
