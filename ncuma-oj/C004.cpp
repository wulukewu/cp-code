#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string s;
int n, m;
set < string > ans;

void func(string t, vector < int > went){
    m = t.size();

    if(n==m){
        if(ans.find(t)==ans.end()){
            ans.insert(t);
        }
    }

    for(int i=0; i<n; i++){
        if(!went[i]){
            went[i] = 1;
            func(t+s[i], went);
            went[i] = 0;
        }
    }
}

int main(){
    cin >> s;
    n = s.size();

    vector < int > went(n, 0);

    func("", went);

    for(auto i: ans){
        cout << i << endl;
    }
}