#include <iostream>
#include <vector>
#include <map>

using namespace std;

signed main(){
    int t;
    cin >> t;

    map < char, int > arr; 

    string s;
    char v;
    // while(cin >> s){
    while(getline(cin, s)){
        for(int i=0; i<s.size(); i++){
            v = s[i];
            if('A' <= v and v <= 'Z'){

            }else if('a' <= v and v <= 'z'){
                v -= 'a' - 'A';
            }else{
                continue;
            }

            if(arr.find(v) == arr.end()){
                arr[v] = 1;
            }else{
                arr[v]++;
            }
        }
    }

    // for(auto i: arr){
    //     cout << i.first << ' ' << i.second << endl;
    // }

    int m = 0;
    for(auto i: arr){
        m = max(m, i.second);
    }
    
    vector < vector < char > > ans(m, vector < char >());
    for(auto i: arr){
        ans[i.second-1].push_back(i.first);
    }

    for(int i=ans.size()-1; i>=0; i--){
        if(ans[i].size() == 0){
            continue;
        }
        for(auto j: ans[i]){
            cout << j << ' ' << arr[j] << endl;
        }
    }
}