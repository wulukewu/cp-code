// ==================================================
// Problem   : ABC384_A - aaaadaa
// URL       : https://atcoder.jp/contests/abc384/tasks/abc384_a
// ==================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// #define int long long
using namespace std;
// #include <fstream>

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n;
    char c1, c2;
    cin >> n >> c1 >> c2;

    string s;
    cin >> s;

    for(int i=0; i<n; i++){
        if(s[i] == c1){
            cout << c1;
        } else {
            cout << c2;
        }
    }
}
