#include <iostream>
#include <stack>

using namespace std;

signed main(){
    stack < int > s;

    string t;
    int a, b, c;
    while(cin >> t){
        if(t=="+"){
            b = s.top();
            s.pop();
            c = s.top();
            s.pop();
            a = b + c;
        }else if(t=="-"){
            b = s.top();
            s.pop();
            c = s.top();
            s.pop();
            a = c - b;
            
        }else if(t=="*"){
            b = s.top();
            s.pop();
            c = s.top();
            s.pop();
            a = b * c;            
        }else if(t=="/"){
            b = s.top();
            s.pop();
            c = s.top();
            s.pop();
            a = c / b;

        }else{
            a = stoi(t);
            // cout << a << endl;
        }
        s.push(a);
    }

    cout << s.top();

}