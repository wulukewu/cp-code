#include <iostream>
#include <vector>
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, n, q;
    cin >> m >> n >> q;

    int begin_i, begin_j;
    vector < pair < int , pair < int , int > > > bomps;

    vector < vector < int > > arr(m, vector < int > (n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j]==-2){
                begin_i = i;
                begin_j = j;
            }else if(arr[i][j]>0){
                bomps.push_back(make_pair(arr[i][j], make_pair(i, j)));
            }
        }
    }

    int bomps_size = bomps.size();
    for(int i=0; i<bomps_size; i++) {
        cout << bomps[i].first << " " << bomps[i].second.first << " " << bomps[i].second.second << endl;

    }
}