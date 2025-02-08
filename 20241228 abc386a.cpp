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
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector <int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    sort(v.begin(), v.end());

    int count = 1;
    for(int i=0; i<3; i++) {
        if(v[i] != v[i+1]) {
            count++;
        }
    }

    if(count == 2){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
