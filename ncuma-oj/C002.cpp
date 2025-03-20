#include <iostream>

using namespace std;

int func(string a, string b){
    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;
    while((i < n) and (j < m)){
        if(a[i]==b[j]){
            j++;
            if(j==m){
                return 1;
            }
        }
        i++;
    }

    return 0;
}

signed main(){
    int n;
    cin >> n;

    int exc = 'a' - 'A';

    string s;
    for(int i=0; i<n; i++){
        cin >> s;

        for(int i=0; i<s.size(); i++){
            if('A' <= s[i] and s[i] <= 'Z'){
                s[i] += exc;
            }
        }

        if(func(s, "fish")){
            if(func(s, "happy")){
                cout << "happy" << endl;
            }else{
                cout << "nothappy" << endl;
            }
        }else{
            cout << "notfish" << endl;
        }
    }
}