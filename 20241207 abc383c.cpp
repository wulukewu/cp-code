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
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, d;
    cin >> h >> w >> d;

    vector < vector < int > > arr(h, vector < int > (w, 0));

    string t;
    int hums = 0;
    for(int i=0; i<h; i++){
        cin >> t;
        for(int j=0; j<w; j++){
            if(t[j] == '#')arr[i][j] = 1;
            else if(t[j] == '.') arr[i][j] = 0;
            else{
                arr[i][j] = 2;
                hums++;
            }
        }
    }
    
    int s=hums;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){

            if(arr[i][j]==2){

                // up
                int up = min(i, d);
                for(int k=1; k<=up; k++){
                    if(arr[i-k][j]==1) break;
                    if(arr[i-k][j]==0){
                        arr[i-k][j] = 3;
                        s++;
                    }
                }

                // down
                int down = min(h-i-1, d);
                for(int k=1; k<=down; k++){
                    if(arr[i+k][j]==1) break;
                    if(arr[i+k][j]==0){
                        arr[i+k][j] = 3;
                        s++;
                    }
                }

                // left
                int left = min(j, d);
                for(int k=1; k<=left; k++){
                    if(arr[i][j-k]==1) break;
                    if(arr[i][j-k]==0){
                        arr[i][j-k] = 3;
                        s++;
                    }
                }

                // right
                int right = min(w-j-1, d);
                for(int k=1; k<=right; k++){
                    if(arr[i][j+k]==1) break;
                    if(arr[i][j+k]==0){
                        arr[i][j+k] = 3;
                        s++;
                    }
                }
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << s;
}
