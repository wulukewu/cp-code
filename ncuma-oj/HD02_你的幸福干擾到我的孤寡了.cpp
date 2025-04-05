#include <iostream>
#include <stack>

using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;

        int n = a.size();
        if(n%2){
            cout << "No" << endl;
            continue;
        }

        bool det = true;
        stack < char > s;
        for(int i=0; i<n; i++){
            if(a[i]=='(' or a[i]=='{' or a[i]=='[' or a[i]=='<'){
                s.push(a[i]);
            }else if((s.top()=='(' and a[i]==')') or (s.top()=='{' and a[i]=='}') or (s.top()=='[' and a[i]==']') or (s.top()=='<' and a[i]=='>')){
                s.pop();
            }else{
                det = false;
                break;
            }
        }
        if(det){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}