/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 UVa // 11461 // Square Numbers
 https://onlinejudge.org/external/114/11461.pdf

 AC // C++11 // 0 ms
 #30407078 // 2025-05-17 22:48:48 +0800 // 2 attempts
 time limit 1000 ms

 cp-code:submission-metadata
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b;
    while(cin >> a){
        cin >> b;

        if(a==0 and b==0){
            break;
        }

        int n = 0;
        int i = 1;
        while(i*i<a){
            i++;
        }

        while(i*i<=b){
            n++;
            i++;
        }

        cout << n << endl;
    }
}