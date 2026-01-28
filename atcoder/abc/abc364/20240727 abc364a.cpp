// ==================================================
// Problem   : ABC364_A - Glutton Takahashi
// URL       : https://atcoder.jp/contests/abc364/tasks/abc364_a
// ==================================================

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int sweet = 0;
    int salty = 0;
    bool det = true;

    for(int i=0; i < n; i++){
        string s;
        cin >> s;

        if(sweet>=2){
            det = false;
        }

        if(s == "sweet"){
            sweet++;
            salty = 0;
        }
        else{
            salty++;
            sweet = 0;
        }
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
