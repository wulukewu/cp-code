/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 UVa // 10327 // Flip Sort
 https://onlinejudge.org/external/103/10327.pdf

 WA // C++11 // 40 ms
 #30413511 // 2025-05-19 21:58:40 +0800
 time limit 3000 ms

 cp-code:submission-metadata
*/

#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int n;
    while(cin >> n){
        vector < int > arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int m = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]>arr[j]){
                    swap(arr[i], arr[j]);
                    m++;
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;

        cout << "Minimum exchange operations : " << m << endl;
    }
}