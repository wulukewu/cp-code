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

    int q;
    cin >> q;

    int ans, x, y, xx, yy;
    for(int qq=0; qq<q; qq++){
        int l, r;
        cin >> l >> r;

        ans = 0;
        x = mp[l-1].first;
        y = mp[l-1].second;
        for(int m=l+d; m<=r; m+=d){
            xx = mp[m-1].first;
            yy = mp[m-1].second;
            ans += abs(xx-x) + abs(yy-y);
            x = xx;
            y = yy;
        }
        cout << ans << endl;
    }
    
}