#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 1){
        return 1;
    }

    a %= b;
    if(a==0){
        return b;
    }else{
        return gcd(b, a);
    }
}

signed main(){
    int n;
    cin >> n;

    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        if(a > b){
            cout << gcd(a, b) << endl;
        }else{
            cout << gcd(b, a) << endl;
        }
    }
}