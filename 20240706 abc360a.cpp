#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    // cout << s;

    int R, M, S;
    for(int i=0; i<s.length(); i++){
        // cout << s[i] << endl;
        if(s[i]=='R'){R = i;}
        else if(s[i]=='M'){M = i;}
        else if(s[i]=='S'){S = i;}
    }
    if(R<M){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}