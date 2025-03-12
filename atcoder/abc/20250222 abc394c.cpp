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
#define int long long
// #define float double
// #define float long double
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
    
    int n=s.size();

    for(int i=n-1; i>0; i--){
        if(s[i-1]=='W' and s[i]=='A'){
            s[i-1]='A';
            s[i]='C';
        }
    }

    cout << s;
}
