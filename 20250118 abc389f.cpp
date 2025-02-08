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
#include <fstream>

signed main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    int l, r;
    vector < pair < int, int> > arr;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        arr.push_back(make_pair(l, 1));
        arr.push_back(make_pair(r, -1));
    }

    sort(arr.begin(), arr.end());

    vector < int > ans(n*2);
    int sum = 0;
    

    int q;
    cin >> q;

    
        
}
