#include <iostream>
#include <vector>
// #include <set>

using namespace std;

signed main(){
    vector < int > dp(17, 1);
    for(int i=2; i<17; i++){
        dp[i] = dp[i-1] * 4 - dp[i-2];
    }

    int n;
    while(cin >> n){
        if(n==-1) break;
        if(n%2==1){
            cout << 0 << endl;
            continue;
        }
        cout << dp[n/2+1] << endl;
    }
}

// int n, m;
// vector < vector < int > > arr;
// set < pair < int, int > > s;
// // int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// int d[2][2] = {{1, 0}, {0, 1}};

// void dfs(int ii, int jj){
//     // cout << '-' << endl;
//     // for(int i=0; i<3; i++){
//     //     for(int j=0; j<n; j++){
//     //         cout << arr[i][j];
//     //     }
//     //     cout << endl;
//     // }

//     bool filled = true;
//         for(int i=0; i<3; i++){
//         for(int j=0; j<n; j++){
//             if(arr[i][j]==0){
//                 filled = false;
//                 break;
//             }
//         }
//         if(!filled) break;
//     }

//     if(filled){
//         m++;
//         // cout << "m++" << endl;
//     }

//     int x, y;
//     for(int i=ii; i<3; i++){
//         if(i>ii) jj=0;
//         for(int j=jj; j<n; j++){
//             if(arr[i][j]==1) continue;
//             // filled = false;
//             // for(int k=0; k<4; k++){
//             for(int k=0; k<2; k++){
//                 x = i + d[k][0];
//                 y = j + d[k][1];
//                 if(!(0<=x and x<3 and 0<=y and y<n)) continue;
//                 if(arr[x][y]==1) continue;
//                 // cout << i << ' ' << j << ' ' << x << ' ' << y << endl;
//                 arr[i][j] = 1;
//                 arr[x][y] = 1;
//                 dfs(i, j);
//                 arr[i][j] = 0;
//                 arr[x][y] = 0;
//             }
//         }
//     }
// }

// signed main(){
//     while(cin >> n){
//         if(n==-1) break;
//         else if(n%2==1){
//             cout << 0 << endl;
//             continue;
//         }

//         m = 0;
//         arr = vector < vector < int > > (3, vector < int > (n, 0));
//         dfs(0, 0);
//         cout << m << endl;
//     }
// }



// signed main(){
//     vector < int > dp(16, 0);
//     dp[1] = 3;
//     for(int i=2; i<16; i++){
//         dp[i] = dp[i-1] * 3 + 2;
//     }

//     for(int i=0; i<16; i++){
//         cout << dp[i] << ' ';
//     }
//     cout << endl;

//     int n;
//     while(cin >> n){
//         if(n==-1) break;
//         if(n%2==1){
//             cout << 0 << endl;
//         }else{
//             cout << dp[n/2] << endl;
//         }
//     }
// }