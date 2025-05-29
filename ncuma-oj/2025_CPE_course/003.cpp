#include <iostream>

using namespace std;

int eucli(int a, int b){
    if(a<b) swap(a, b);
    if(b==1) return 1;
    if(a%b==0) return b;
    return eucli(b, a%b);
}

signed main(){
    int a, b, c, d;
    char p;
    int A, B, C;
    while(cin >> a){
        cin >> b >> c >> d;
        cin >> p;

        if(p=='+'){
            A = a * d + c * b;
            B = b * d;
        }else if(p=='-'){
            A = a * d - c * b;
            B = b * d;
        }else if(p=='*'){
            A = a * c;
            B = b * d;
        }else{
            A = a * d;
            B = b * c;
        }
        // cout << A << ' ' << B << endl;

        if(A==0){
            cout << 0 << endl;
        }else if(A%B==0){
            cout << A/B << endl;
        }else{
            C = eucli(abs(A), abs(B));
            // cout << C << endl;

            A /= C;
            B /= C;
            if(A*B<0) cout << "-";
            cout << abs(A) << "/" << abs(B) << endl;
        }
        
    }
}