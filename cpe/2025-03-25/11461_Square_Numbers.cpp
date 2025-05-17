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