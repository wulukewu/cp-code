#include <iostream>
#include <vector>

using namespace std;

signed main(){
    int s1, s2, d;
    cin >> s1 >> s2 >> d;

    vector < int > a(8);
    vector < int > b(8);

    for(int i=0; i<8; i++){
        a[8-1-i] = s1 % 2;
        s1 /= 2;
        b[8-1-i] = s2 % 2;
        s2 /= 2;
    }

    for(int i=0; i<8; i++){
        cout << a[i];
    }
    cout << ' ';
    for(int i=0; i<8; i++){
        cout << b[i];
    }
    cout << endl;

    for(int i=0; i<8; i++){
        if(i<8-d){
            cout << a[i];
        }else{
            cout << b[i];
        }
    }
    cout << ' ';
    for(int i=0; i<8; i++){
        if(i<8-d){
            cout << b[i];
        }else{
            cout << a[i];
        }
    }

}