#include <iostream>
#include <algorithm>

using namespace std;

signed main(){
    int t;
    cin >> t;

    int n;
    string s, s2;
    for(int i=0; i<t; i++){
        cin >> n >> s;
        s2 = s;
        reverse(s2.begin(), s2.end());

        if(s>s2){
            if(n%2){
                cout << s2 << endl;
            }else{
                cout << s2 << s << endl;
            }
        }else if(s<s2){
            if(n%2){
                cout << s << s2 << endl;
            }else{
                cout << s << endl;
            }
        }else{
            cout << s << endl;
        }
    }
}