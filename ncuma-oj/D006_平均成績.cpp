#include <iostream>
#include <map>

using namespace std;

signed main(){
    int t;
    cin >> t;

    map < string, int > mp;
    mp.insert(make_pair("Hipp0", 98));
    mp.insert(make_pair("Ccshiao", 100));
    mp.insert(make_pair("Ama", 0));
    
    int sum = 98+100+0;
    int sum_count = 3;

    string s, a;
    int b;
    while(t--){
        cin >> s;

        if(s=="del"){
            cin >> a;
            sum -= mp[a];
            mp[a] = -1;
            sum_count--;
        }else if(s=="add"){
            cin >> a >> b;
            mp.insert(make_pair(a, b));
            sum += b;
            sum_count++;
        }else{
            cout << (int)(sum/sum_count) << endl;
        }
    }
}