/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 UVa // 382 // Perfection
 https://onlinejudge.org/external/3/382.pdf

 WA // C++11 // 0 ms
 #30256545 // 2025-03-24 21:30:49 +0800 // 3 attempts
 time limit 3000 ms

 cp-code:submission-metadata
*/

#include <iostream>

using namespace std;

signed main(){

    cout << "PERFECTION OUTPUT" << endl;

    int n, s;
    while(cin >> n){
        if(n==0){
            cout << "END OF OUTPUT";
            break;
        }
        
        s = 0;
        for(int i=1; i<n; i++){
            if(n%i==0){
                s += i;
            }
        }

        printf("%5d  ", n);

        if(s>n){
            cout << "ABUNDANT";
        }else if(s==n){
            cout << "PERFECT";
        }else{
            cout << "DEFICIENT";
        }
        cout << endl;

    }
}