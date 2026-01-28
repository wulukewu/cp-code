// ==================================================
// Problem   : ABC089_D - Practical Skill Test
// URL       : https://atcoder.jp/contests/abc089/tasks/abc089_d
// ==================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int h, w, d;
    cin >> h >> w >> d;

    vector < vector < int > > A(h, vector < int > (w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> A[i][j];
        }
    }

    map < int, pair < int, int > > mp;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            mp[A[i][j]-1] = make_pair(i, j);
        }
    }

    vector < int > arr(h*w);
    for(int i=0; i<d; i++){
        for(int j=i; j<h*w; j+=d){
            if(j==i){
                arr[j] = 0;
                continue;
            }
            arr[j] = arr[j-d] + abs(mp[j].first-mp[j-d].first) + abs(mp[j].second-mp[j-d].second);
        }
    }

    // for(int i=0; i<h*w; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int q;
    cin >> q;

    int ans;
    for(int qq=0; qq<q; qq++){
        int l, r;
        cin >> l >> r;

        ans = arr[r-1] - arr[l-1];
        cout << ans << endl;
    }
    
}