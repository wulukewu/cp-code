#include <iostream>
#include <sstream>
#include <set>

using namespace std;

signed main(){
    set < string > dir;

    string s, d, t;
    char c;
    while(getline(cin, s)){
        // cin.ignore();

        stringstream ss(s);
        while(ss >> d){
            // cout << d << ' ';
            t = "";

            for(int i=0; i<d.size(); i++){
                c = d[i];
                if('a' <= c and c <= 'z'){
                    t += c;
                }else if('A' <= c and c <= 'Z'){
                    t += c + 'a' - 'A';
                }else if(t.size() > 0){
                    if(dir.find(t) == dir.end()){
                        dir.insert(t);
                    }
                    t = "";
                }
            }

            if(dir.find(t) == dir.end() and t.size() > 0){
                dir.insert(t);
            }
        }
    }

    for(auto i: dir){
        cout << i << endl;
    }
}