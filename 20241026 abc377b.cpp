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
    
    vector < int > arr1(8, 0);
    vector < int > arr2(8, 0);
    for(int i=0; i<8; i++){
        string s;
        cin >> s;
        for(int j=0; j<8; j++){
            if(s[j] == '#'){
                arr1[i] = 1;
                arr2[j] = 1;
            }
        }
    }
    int x=0; int y=0;
    for(int i=0; i<8; i++){
        if(arr1[i]==0){
            x++;
        }
        if(arr2[i]==0){
            y++;
        }
    }
    cout << x*y;
}
