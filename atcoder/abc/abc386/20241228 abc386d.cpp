// ==================================================
// Problem   : ABC386_D - Diagonal Separation
// URL       : https://atcoder.jp/contests/abc386/tasks/abc386_d
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
#include <math.h>
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    vector < int > X(m);
    vector < int > Y(m);
    vector < int > C(m);

    for(int i = 0; i < m; i++) {
        char c;
        cin >> X[i] >> Y[i] >> c;
        if(c == 'B') {
            C[i] = 0;
        } else {
            C[i] = 1;
        }
    }

    bool det = true;
    

    // bool det = true;
    // vector < int > min_black_row(n, -1);
    // vector < int > max_white_row(n, -1);
    // vector < int > min_black_col(n, -1);
    // vector < int > max_white_col(n, -1);

    // for(int i=0; i<m; i++){
    //     if(C[i] == 0){
    //         if(min_black_row[X[i]-1] == -1){
    //             min_black_row[X[i]-1] = i;
    //         }else{
    //             det = false;
    //             break;
    //         }
    //         if(min_black_col[Y[i]-1] == -1){
    //             min_black_col[Y[i]-1] = i;
    //         }else{
    //             det = false;
    //             break;
    //         }
    //     }else{
    //         if(max_white_row[X[i]-1] == -1){
    //             max_white_row[X[i]-1] = i;
    //         }else{
    //             det = false;
    //             break;
    //         }
    //         if(max_white_col[Y[i]-1] == -1){
    //             max_white_col[Y[i]-1] = i;
    //         }else{
    //             det = false;
    //             break;
    //         }
    //     }
    // }

    // // for(int i=0; i<n; i++){
    // //     cout << min_black_row[i] << " " << max_white_row[i] << " " << min_black_col[i] << " " << max_white_col[i] << endl;
    // // }

    // if(det){
    //     int min_black_row_max = -1;
    //     int max_white_row_min = m;
    //     int min_black_col_max = -1;
    //     int max_white_col_min = m;
        
    //     for(int i=0; i<n; i++){
    //         if(min_black_row[i] != -1){
    //             if(min_black_row[i] < min_black_row_max){
    //                 det = false;
    //                 break;
    //             }else{
    //                 min_black_row_max = min_black_row[i];
    //             }
    //         }
    //         if(max_white_row[i] != -1){
    //             if(max_white_row[i] > max_white_row_min){
    //                 det = false;
    //                 break;
    //             }else{
    //                 max_white_row_min = max_white_row[i];
    //             }
    //         }
    //         if(min_black_col[i] != -1){
    //             if(min_black_col[i] < min_black_col_max){
    //                 det = false;
    //                 break;
    //             }else{
    //                 min_black_col_max = min_black_col[i];
    //             }
    //         }
    //         if(max_white_col[i] != -1){
    //             if(max_white_col[i] > max_white_col_min){
    //                 det = false;
    //                 break;
    //             }else{
    //                 max_white_col_min = max_white_col[i];
    //             }
    //         }
    //     }

    //     for(int i=0; i<n; i++){
    //         if(min_black_row[i] != -1 and max_white_row[i] != -1){
    //             if(min_black_row[i] > max_white_row[i]){
    //                 det = false;
    //                 break;
    //             }
    //         }
    //         if(min_black_col[i] != -1 and max_white_col[i] != -1){
    //             if(min_black_col[i] > max_white_col[i]){
    //                 det = false;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // if(det){
    //     cout << "Yes";
    // }else{
    //     cout << "No";
    // }

}
