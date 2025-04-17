#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n, k;
    string m;

    cin >> n >> k >> m;

    stack < char > s;

    for(char d: m){
        while(!s.empty() and k>0 and d<s.top()){
            s.pop();
            k--;
        }
        s.push(d);
    }

    while(k>0){
        s.pop();
        k--;
    }

    string ans = "";
    while(!s.empty()){
        ans = s.top() + ans;
        s.pop();
    }

    // cout << ans;
    size_t ans_out = ans.find_first_not_of('0');
    if (ans_out == string::npos) {
        cout << "0" << endl;
    } else {
        cout << ans.substr(ans_out) << endl;
    }

}