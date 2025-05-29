#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

signed main(){
    int n;
    cin >> n;

    map < char, int > mp;
    char c;
    while(cin.get(c)){
        if('A'<=c and c<='Z'){}
        else if('a'<=c and c<='z'){
            c -= 'a' - 'A';
        }else continue;
        // cout << c << endl;

        if(mp.find(c) == mp.end()){
            mp.insert(make_pair(c, 1));
        }else{
            mp[c]++;
        }
    }
    vector < pair < int, char > > arr;
    for(auto i: mp){
        // cout << i.first << ' ' << i.second << endl;
        arr.push_back(make_pair(1e8-i.second, i.first));
    }

    sort(arr.begin(), arr.end());
    // reverse(arr.begin(), arr.end());

    for(auto i: arr){
        cout << i.second << ' ' << 1e8-i.first << endl;
    }
}