#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <random>
#include <set>
#include <map>
#include <stack>
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
    
    int q;
    cin >> q;

    stack < int > arr;

    int type, x;
    for(int i=0; i<q; i++){
        cin >> type;
        if(type == 1){
            cin >> x;
            arr.push(x);
        }else{
            if(arr.size()>0){
                cout << arr.top() << endl;
                arr.pop();
            }else{
                cout << 0 << endl;
            }
        }
    }
}
