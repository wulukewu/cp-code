// ==================================================
// Problem   : ABC380_A - 123233
// URL       : https://atcoder.jp/contests/abc380/tasks/abc380_a
// ==================================================

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <math.h>
// #define int long long
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;

    int a=0, b=0, c=0;
    for(int i=0; i<6; i++){
        if(s[i]=='1')a++;
        else if(s[i]=='2')b++;
        else if(s[i]=='3')c++;
    }

    if(a==1 and b==2 and c==3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
