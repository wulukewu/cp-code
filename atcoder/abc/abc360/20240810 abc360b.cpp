// ==================================================
// Problem   : ABC360_B - Vertical Reading
// URL       : https://atcoder.jp/contests/abc360/tasks/abc360_b
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
#include <fstream>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    int j=0;
    int ss = s.size();
    int tt = t.size();
    for(int i=0; i<ss; i++){
        if(s[i]==t[j]){
            j++;
        }
    }

    // cout << j << endl;

    bool det;
    if(j == tt){
        det = true;
    }else{
        det = false;
    }
    if(tt==1 && s[ss-1]==t[0]){
        det = false;
    }

    if(det){
        cout << "Yes";
    }else{
        cout << "No";
    }


}
