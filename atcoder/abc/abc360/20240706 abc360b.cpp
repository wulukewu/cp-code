// ==================================================
// Problem   : ABC360_B - Vertical Reading
// URL       : https://atcoder.jp/contests/abc360/tasks/abc360_b
// ==================================================

#include <iostream>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;

    bool det = true;
    vector <string> arr;
    int s1, s2=0, t=0;
    for(s1=0; s < S.length(); s++){
        if(S[s1] == T[t]){
            arr.push_back(S[s2:s1+1])
            t++;
            s2 = s1;
        }
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }

}