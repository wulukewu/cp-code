// ==================================================
// Problem   : ABC364_B - Grid Walk
// URL       : https://atcoder.jp/contests/abc364/tasks/abc364_b
// ==================================================

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int h, w, si, sj;
    cin >> h >> w >> si >> sj;
    si --; sj--;

    vector < vector <int> > arr(h,vector <int> (w,0));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char s;
            cin >> s;
            if(s=='#'){
                arr[i][j] = 1;
            }
        }
    }

    // for(int i=0; i<h; i++){
    //     for(int j=0; j<w; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    string x;
    cin >> x;

    int l = x.length();
    int xo, yo;
    for(int idx=0; idx<l; idx++){
        // cout << idx << x[idx] << ' ' << si << sj << endl;
        if(x[idx]=='L' and sj!=0){
            xo=-1;
            yo=0;
            // cout << 'L' << endl;
        }
        else if(x[idx]=='R' and sj<w-1){
            xo=1;
            yo=0;
            // cout << 'R' << endl;
        }
        else if(x[idx]=='U' and si!=0){
            xo=0;
            yo=-1;
            // cout << 'U' << endl;
            }
        else if(x[idx]=='D' and si<h-1){
            xo=0;
            yo=1;
            // cout << 'D' << endl;
        }
        else{continue;}

        // cout << si << ' ' << yo << ' ' << sj << ' ' << xo << endl;
        if(arr[si+yo][sj+xo] == 0){
            si += yo;
            sj += xo;
        }
        // cout << si << ' ' << sj << endl;
    }

    cout << si+1 << ' ' << sj+1 << endl;
}
