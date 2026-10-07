/*
'##:::::::'##::::'##:'##:::'##:'########:
 ##::::::: ##:::: ##: ##::'##:: ##.....::
 ##::::::: ##:::: ##: ##:'##::: ##:::::::
 ##::::::: ##:::: ##: #####:::: ######:::
 ##::::::: ##:::: ##: ##. ##::: ##...::::
 ##::::::: ##:::: ##: ##:. ##:: ##:::::::
 ########:. #######:: ##::. ##: ########:
........:::.......:::..::::..::........::

 UVa // 12250 // Language Detection
 https://onlinejudge.org/external/122/12250.pdf

 AC // C++11 // 0 ms
 #30256533 // 2025-03-24 21:28:09 +0800
 time limit 3000 ms

 cp-code:submission-metadata
*/

#include <iostream>

using namespace std;

signed main(){
    string s;
    int i = 1;
    while(cin >> s){
        if(s=="#")break;

        cout << "Case " << i << ": ";
        if(s=="HELLO"){
            cout << "ENGLISH" << endl;
        }else if(s=="HOLA"){
            cout << "SPANISH" << endl;
        }else if(s=="HALLO"){
            cout << "GERMAN" << endl;
        }else if(s=="BONJOUR"){
            cout << "FRENCH" << endl;
        }else if(s=="CIAO"){
            cout << "ITALIAN" << endl;
        }else if(s=="ZDRAVSTVUJTE"){
            cout << "RUSSIAN" << endl;
        }else{
            cout << "UNKNOWN" << endl;
        }

        i++;
    }
}