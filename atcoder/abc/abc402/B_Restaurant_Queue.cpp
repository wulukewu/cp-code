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
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define Fio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
// #include <fstream>

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int q;
    cin >> q;
    
    int t, x;
    queue < int > arr;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> x;
            arr.push(x);
        }else{
            cout << arr.front() << endl;
            arr.pop();
        }
    }
}
