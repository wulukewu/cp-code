// ==================================================
// Problem   : ABC398_D - Bonfire
// Limits    : 2 sec / 1024 MB
// URL       : https://atcoder.jp/contests/abc398/tasks/abc398_d
// ==================================================

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
    
    int n, r, c;
    cin >> n >> r >> c;

    // int m = 4*n+1;

    string s;
    cin >> s;

    // vector < vector < int > > arr(m, vector < int > (m, 0));
    
    // int x=0;
    // int y=0;
    // arr[2*n+x][2*n+y] = 1;

    // for(int t=0; t<n; t++){
        
    //     if(s[t]=='N'){
    //         r++;
    //         x++;
    //     }else if(s[t]=='W'){
    //         c++;
    //         y++;
    //     }else if(s[t]=='S'){
    //         r--;
    //         x--;
    //     }else if(s[t]=='E'){
    //         c--;
    //         y--;
    //     }

    //     arr[2*n+x][2*n+y] = 1;
        
    //     // cout << r << ' ' << c << endl;

    //     // for(int i=0; i<m; i++){
    //     //     for(int j=0; j<m; j++){
    //     //         cout << arr[i][j];
    //     //     }cout << endl;
    //     // }
        
    //     cout << arr[2*n+r][2*n+c];

    // }

    set < pair < int, int > > arr;

    int x = 0;
    int y = 0;
    arr.insert(make_pair(x, y));
    
    // cout << x << ' ' << y << '\t' << x+r << ' ' << y+c << endl;
    
    for(int t=0; t<n; t++){
        if(s[t]=='N'){
            x++;
        }else if(s[t]=='W'){
            y++;
        }else if(s[t]=='S'){
            x--;
        }else if(s[t]=='E'){
            y--;
        }

        // cout << x << ' ' << y << '\t' << x+r << ' ' << y+c << endl;

        arr.insert(make_pair(x, y));

        if(arr.find(make_pair(x+r, y+c)) == arr.end()){
            cout << 0;
        }else{
            cout << 1;
        }
    }

}
